
private _targetPos = uiNamespace getVariable "nfst_moduleAirStrikePos";

params ["_idcPlaneType", "_idcPlaneNumber", "_idcFormation", "_idcBombType", "_idcBombNumber", "_idcBombDelay", "_idcFlightHeight", "_idcFlightSpeed", "_idcSpawnBearing", "_idcSpawnDistance", "_idcDespawnBearing", "_idcDespawnDistance"];

private _planeType       = lbData [_idcPlaneType, lbCurSel _idcPlaneType];
private _formation       = lbData [_idcFormation, lbCursel _idcFormation];
private _bombType        = lbData [_idcBombType, lbCursel _idcBombType]  ;
private _planeNumber     = sliderPosition _idcPlaneNumber    ;
private _bombNumber      = sliderPosition _idcBombNumber     ;
private _bombDelay       = sliderPosition _idcBombDelay      ;
private _flightHeight    = sliderPosition _idcFlightHeight   ;
private _flightSpeed     = sliderPosition _idcFlightSpeed    ;
private _spawnBearing    = sliderPosition _idcSpawnBearing   ;
private _spawnDistance   = sliderPosition _idcSpawnDistance  ;
private _despawnBearing  = sliderPosition _idcDespawnBearing ;
private _despawnDistance = sliderPosition _idcDespawnDistance;

closeDialog 0;

/*
1 - Compute spawn point and despawn point coordinates
2 - Compute relative formation offsets
3 - Compute absolute plane positions
4 - Create planes
5 - Add waypoints
*/

// 1
private _angleToSpawn    = 90 - _spawnBearing  ;
private _angleToDespawn  = 90 - _despawnBearing;
private _bearingToTarget = (_spawnBearing + 180) % 360;
private _angleToTarget   = 90 - _bearingToTarget;

private _spawnDeltaX   = _spawnDistance   * cos(_angleToSpawn  );
private _spawnDeltaY   = _spawnDistance   * sin(_angleToSpawn  );
private _despawnDeltaY = _despawnDistance * sin(_angleToDespawn);
private _despawnDeltaX = _despawnDistance * cos(_angleToDespawn);

private _targetX    = _targetPos select 0;
private _targetY    = _targetPos select 1;
private _targetEndX = _targetX + _bombNumber * _bombDelay * (_flightSpeed/3.6) * cos(_angleToTarget);
private _targetEndY = _targetY + _bombNumber * _bombDelay * (_flightSpeed/3.6) * sin(_angleToTarget);

private _spawnPosX   = _targetX + _spawnDeltaX  ;
private _spawnPosY   = _targetY + _spawnDeltaY  ;
private _despawnPosX = _targetX + _despawnDeltaX;
private _despawnPosY = _targetY + _despawnDeltaY;

// 2 TODO
private _formationPositionOffsetsSpawn   = [_formation, _planeNumber, _bearingToTarget] call nfst_fnc_commonComputeFormationOffsets;
private _formationPositionOffsetsDespawn = [_formation, _planeNumber, _despawnBearing ] call nfst_fnc_commonComputeFormationOffsets;

// 3 TODO
private _planeSpeedX = _flightSpeed * cos(_angleToSpawn+180) / 3.6;
private _planeSpeedY = _flightSpeed * sin(_angleToSpawn+180) / 3.6;
private _planeSpeedZ = 0;
private _planeSpeedVector = [_planeSpeedX, _planeSpeedY, _planeSpeedZ];

private _glideTime  = _flightHeight / 10;
private _bombGlideX = _planeSpeedX * _glideTime;
private _bombGlideY = _planeSpeedY * _glideTime;
systemChat format ["X : %1, Y : %2", _bombGlideX, _bombGlideY];

private _spawnPos   = [];
private _despawnPos = [];
private _bombingPos = [];
private _bombingEnd = [];
private _planePositions = [];
private _offsetSpawnX   = 0;
private _offsetSpawnY   = 0;
private _offsetDespawnX = 0;
private _offsetDespawnY = 0;

for "_i" from 1 to _planeNumber do
{
  _offsetSpawnX   = _formationPositionOffsetsSpawn   select (_i-1) select 0;
  _offsetSpawnY   = _formationPositionOffsetsSpawn   select (_i-1) select 1;
  _offsetDespawnX = _formationPositionOffsetsDespawn select (_i-1) select 0;
  _offsetDespawnY = _formationPositionOffsetsDespawn select (_i-1) select 1;

  _spawnPos   = [_spawnPosX   + _offsetSpawnX  , _spawnPosY   + _offsetSpawnY  , 0];
  _despawnPos = [_despawnPosX + _offsetDespawnX, _despawnPosY + _offsetDespawnY, 0];
  _bombingPos = [_targetX     + _offsetSpawnX  - _bombGlideX, _targetY     + _offsetSpawnY - _bombGlideY, 0];
  _bombingEnd = [_targetEndX  + _offsetSpawnX  - _bombGlideX, _targetEndY  + _offsetSpawnY - _bombGlideY, 0];

  _planePositions append [[_spawnPos, _bombingPos, _bombingEnd, _despawnPos]];
};


// 4

{
    _spawnPos   = _x select 0;
    _bombingPos = _x select 1;
    _bombingEnd = _x select 2;
    _despawnPos = _x select 3;

    private _plane = _planeType createVehicle _spawnPos;
    [_plane, _flightHeight, _spawnPos, "ATL"] call BIS_fnc_setHeight;
    _plane setDir _bearingToTarget;
    _plane setVelocity _planeSpeedVector;
    _plane flyInHeightASL [_flightHeight, _flightHeight, _flightHeight];
    _plane limitSpeed _flightSpeed;

    private _compatibleBombs = missionNamespace getVariable "nfst_moduleAirStrikeBomberPlanes";
    {
      if ((_x select 0) == _planeType) then
      {
        _planePylons = _x select 3;
        {
          _currentPylon = _x select 0;
          _pylonMagazines = _x select 1;
          {
            if ((_x select 0) == _bombType) then
            {
              _magazineAmmoCount = _x select 1;
              _plane setPylonLoadOut [_currentPylon, _bombType];
              _plane setAmmoOnPylon [_currentPylon, _magazineAmmoCount];
            };
          } forEach _pylonMagazines;
        } forEach _planePylons;
      };
    } forEach _compatibleBombs;

    _planeWeapons = weapons _plane;
    _activeWeapon = "";
    _fireMode = "";
    {
      _cfgWeapon = configName (configFile >> "CfgWeapons" >> _x);
      _weaponMagazines = getArray (configfile >> "CfgWeapons" >> _cfgWeapon >> "magazines");
      if (_bombType in _weaponMagazines) then
      {
        _activeWeapon = _x;
        _fireMode = (getArray (configFile >> "CfgWeapons" >> _cfgWeapon >> "modes")) select 0;
      };
    } forEach _planeWeapons;

    private _planeGroup = createVehicleCrew _plane;
    driver _plane disableAI "FSM";

    // TODO : add objects to curators
    /*
    {
      [_x, [_plane], true] remoteExec ["addCuratorEditableObjects", 2];
    } forEach allCurators;*/

    // TODO : guide missile to target
/*
    _plane addEventHandler
    ["Fired",
      {
        params ["_unit", "_weapon", "_muzzle", "_mode", "_ammo", "_magazine", "_projectile", "_gunner"];
        [_unit, _projectile] execVM '\x\nfst\addons\modules\functions\fnc_moduleAirStrikeDoGuideBomb.sqf';
      }
    ];*/

    private _bombingWP = _planeGroup addWaypoint [_bombingPos, -1];
    _bombingWP setWaypointCompletionRadius 1;
    _bombingWP setWaypointStatements
    [format ["(vehicle this) distance2D %1 <= 10", waypointPosition _bombingWP], format ["[this, %1, %2, %3, %4] execVM '\x\nfst\addons\modules\functions\fnc_moduleAirStrikeDoBombingRun.sqf';", _bombNumber, _bombDelay, str _activeWeapon, str _fireMode]];

    //private _bombingEndWP = _planeGroup addWaypoint [_bombingEnd, -1];
    //_bombingEndWP setWaypointCompletionRadius 10;

    private _despawnWP = _planeGroup addWaypoint [_despawnPos, 5];
    _despawnWP setWaypointCompletionRadius 10;
    _despawnWP setWaypointStatements
    ["true", "[this] execVM '\x\nfst\addons\modules\functions\fnc_moduleAirStrikeDoDespawn.sqf';"];

} forEach _planePositions;
