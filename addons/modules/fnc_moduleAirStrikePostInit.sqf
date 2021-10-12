private _targetPos = uiNamespace getVariable "nfst_moduleAirStrikePos";

private _planeNumber     = sliderPosition 1900;
private _planeType       = lbData [2100, lbCurSel 2100];
private _formation       = lbData [2101, lbCursel 2101];
private _bombType        = lbData [2102, lbCursel 2102];
private _bombNumber      = sliderPosition 1901;
private _bombDelay       = sliderPosition 1902;
private _flightHeight    = sliderPosition 1903;
private _flightSpeed     = sliderPosition 1904;
private _spawnBearing    = sliderPosition 1905;
private _spawnDistance   = sliderPosition 1906;
private _despawnBearing  = sliderPosition 1907;
private _despawnDistance = sliderPosition 1908;

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
private _spawnPos   = [];
private _despawnPos = [];
private _bombingPos = [];
private _bombingEnd = [];
private _planePositions = [];
private _offsetSpawnX = 0;
private _offsetSpawnY = 0;
private _offsetDespawnX = 0;
private _offsetDespawnY = 0;

for "_i" from 1 to _planeNumber do
{
  _offsetSpawnX   = _formationPositionOffsetsSpawn   select (_i-1) select 0;
  _offsetSpawnY   = _formationPositionOffsetsSpawn   select (_i-1) select 1;
  _offsetDespawnX = _formationPositionOffsetsDespawn select (_i-1) select 0;
  _offsetDespawnY = _formationPositionOffsetsDespawn select (_i-1) select 1;

  _spawnPos   = [_spawnPosX   + _offsetSpawnX  , _spawnPosY   + _offsetSpawnY  , 0];
  _bombingPos = [_targetX     + _offsetSpawnX  , _targetY     + _offsetSpawnY  , 0];
  _bombingEnd = [_targetEndX  + _offsetSpawnX  , _targetEndY  + _offsetSpawnY  , 0];
  _despawnPos = [_despawnPosX + _offsetDespawnX, _despawnPosY + _offsetDespawnY, 0];

  _planePositions append [[_spawnPos, _bombingPos, _bombingEnd, _despawnPos]];
};


// 4
private _planeSpeedX = _flightSpeed * cos(_angleToSpawn+180) / 3.6;
private _planeSpeedY = _flightSpeed * sin(_angleToSpawn+180) / 3.6;
private _planeSpeedZ = 0;
private _planeSpeedVector = [_planeSpeedX, _planeSpeedY, _planeSpeedZ];
systemChat str ((vectorMagnitude _planeSpeedVector) * 3.6);

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
    // TODO : not working
    /*
    {
      [_x, [_plane], true] remoteExec ["addCuratorEditableObjects", 2];
    } forEach allCurators;*/


    _plane addEventHandler
    ["Fired",
      {
        params ["_unit", "_weapon", "_muzzle", "_mode", "_ammo", "_magazine", "_projectile", "_gunner"];
        _unit execVM '\x\nfst\addons\modules\fnc_moduleAirStrikeDoGuideBomb.sqf';
      }
    ];

    private _bombingWP = _planeGroup addWaypoint [_bombingPos, -1];
    _bombingWP setWaypointCompletionRadius 1;
    _bombingWP setWaypointStatements
    ["true", format ["[this, %1, %2, %3, %4] execVM '\x\nfst\addons\modules\fnc_moduleAirStrikeDoBombingRun.sqf';", _bombNumber, _bombDelay, str _activeWeapon, str _fireMode]];

    private _bombingEndWP = _planeGroup addWaypoint [_bombingEnd, -1];
    _bombingEndWP setWaypointCompletionRadius 10;

    private _despawnWP = _planeGroup addWaypoint [_despawnPos, 5];
    _despawnWP setWaypointCompletionRadius 10;
    _despawnWP setWaypointStatements
    ["true", "[this] execVM '\x\nfst\addons\modules\fnc_moduleAirStrikeDoDespawn.sqf';"];

} forEach _planePositions;
