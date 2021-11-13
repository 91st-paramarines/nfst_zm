private _targetPos = uiNamespace getVariable "nfst_moduleAirStrikePos";

params ["_idcPlaneType", "_idcPlaneNumber", "_idcFormation", "_idcBombType", "_idcBombNumber", "_idcBombDelay", "_idcDropHeight", "_idcFlightSpeed", "_idcSpawnBearing", "_idcSpawnDistance", "_idcDespawnBearing", "_idcDespawnDistance"];

private _planeType       = lbData [_idcPlaneType, lbCurSel _idcPlaneType];
private _formation       = lbData [_idcFormation, lbCursel _idcFormation];
private _bombType        = lbData [_idcBombType, lbCursel _idcBombType]  ;
private _planeNumber     = sliderPosition _idcPlaneNumber    ;
private _bombNumber      = sliderPosition _idcBombNumber     ;
private _bombDelay       = sliderPosition _idcBombDelay      ;
private _dropHeight      = sliderPosition _idcDropHeight     ;
private _flightSpeed     = sliderPosition _idcFlightSpeed    ;
private _spawnBearing    = sliderPosition _idcSpawnBearing   ;
private _spawnDistance   = sliderPosition _idcSpawnDistance  ;
private _despawnBearing  = sliderPosition _idcDespawnBearing ;
private _despawnDistance = sliderPosition _idcDespawnDistance;

closeDialog 0;

// Prepare some flight parameters
private _bearingToTarget  = (_spawnBearing + 180) % 360;
private _planeSpeedVector = [[_flightSpeed / 3.6, 0, 0], 90 - _spawnBearing, 2] call BIS_fnc_rotateVector3D;
private _flightHeight     = _dropHeight + getTerrainHeightASL _targetPos;

// Compute spawn, despawn and targets positions for all planes
private _formationPositionOffsetsSpawn   = [_formation, _planeNumber, _bearingToTarget] call nfst_fnc_commonComputeFormationOffsets;
private _formationPositionOffsetsDespawn = [_formation, _planeNumber, _despawnBearing ] call nfst_fnc_commonComputeFormationOffsets;
private _spawnPos   = _targetPos getPos [_spawnDistance  , _spawnBearing  ];
private _despawnPos = _targetPos getPos [_despawnDistance, _despawnBearing];

// Package it all
private _planePositions = [];
for "_i" from 0 to _planeNumber-1 do
{
  private _bombingPos = [];
  private _targets    = [];
  for "_j" from 0 to _bombNumber-1 do
  {
    private _formationCorrected = _targetPos vectorAdd (_formationPositionOffsetsSpawn select _i);
    private _distanceCorrection = _j * _bombDelay;
    private _bearingCorrection  = [[_distanceCorrection, 0, 0], 90 - _spawnBearing, 2] call BIS_fnc_rotateVector3D;
    private _movementCorrected  = _formationCorrected vectorAdd _bearingCorrection;
    private _glideBearingCorrection = [[-500 + _j * _bombDelay, 0, 0], 90 - _spawnBearing, 2] call BIS_fnc_rotateVector3D;
    private _glideCorrected     = _movementCorrected vectorAdd _glideBearingCorrection;

    _bombingPos append [_glideCorrected];
    _targets append [_movementCorrected];
  };

  _planePositions append
  [[
      _spawnPos   vectorAdd (_formationPositionOffsetsSpawn   select _i),
      _bombingPos,
      _despawnPos vectorAdd (_formationPositionOffsetsDespawn select _i),
      _targets
  ]];
};

// Main loop
{
    _spawnPos   = _x select 0;
    _bombingPos = _x select 1;
    _despawnPos = _x select 2;
    _targets    = _x select 3;

    // Initialize the plane
    private _plane = _planeType createVehicle _spawnPos;
    [_plane, _flightHeight, _spawnPos] call BIS_fnc_setHeight;
    _plane setDir _bearingToTarget;
    _plane setVelocity _planeSpeedVector;
    _plane flyInHeightASL [_flightHeight, _flightHeight, _flightHeight];
    _plane limitSpeed _flightSpeed;

    private _planeGroup = createVehicleCrew _plane;

    // Set the plane's pylons with the requested ordnance
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

    // Get the plane weapon that fires the requested ordnance
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

    // Set bomb drop waypoints
    {
      private _bombingWP = _planeGroup addWaypoint [_x, 5];
      _bombingWP setWaypointCompletionRadius 100;
      _bombingWP setWaypointStatements
      ["true", format ["[this, %1, %2, %3, %4, %5, %6] execVM '\x\nfst\addons\modules\functions\fnc_moduleAirStrikeDoBombTarget.sqf';", str _activeWeapon, _targets select _forEachIndex, _bearingToTarget, _planeSpeedVector, _flightHeight, _flightSpeed]];
    } forEach _bombingPos;

    // Add the despawn waypoint
    private _despawnWP = _planeGroup addWaypoint [_despawnPos, 5];
    _despawnWP setWaypointCompletionRadius 10;
    _despawnWP setWaypointStatements
    ["true", "[this] execVM '\x\nfst\addons\modules\functions\fnc_moduleAirStrikeDoDespawn.sqf';"];

/*
    // Carry out the fire mission
    _planeSide = side _plane;
    [_plane, _targets, _planeSide, _activeWeapon, _planeSpeedVector, _flightHeight, _flightSpeed, _despawnBearing, _despawnPos] spawn
    {
      params ["_plane","_targets", "_planeSide", "_activeWeapon", "_planeSpeedVector", "_flightHeight", "_flightSpeed", "_despawnBearing", "_despawnPos"];
      {
        waituntil {(getposasl _plane) distance _x < 1000};

        private _targetType = if (_planeSide getfriend west > 0.6) then {"LaserTargetW"} else {"LaserTargetE"};
        _target = createvehicle [_targetType,_x, [],0,"none"];
        _plane reveal lasertarget _target;
        _plane dowatch lasertarget _target;
        _plane dotarget lasertarget _target;

        _planeDriver = driver _plane;
        _planeDriver fireattarget [_target, _activeWeapon];
      } forEach _targets;

      {
        _plane deleteVehicleCrew _x;
        systemChat "Del";
      } forEach crew _plane;
      _plane setDir _despawnBearing;
      _plane setVelocity _planeSpeedVector;
      _plane flyInHeightASL [_flightHeight, _flightHeight, _flightHeight];
      _plane limitSpeed _flightSpeed;
      private _planeGroup = createVehicleCrew _plane;
      driver _plane disableAI "FSM";

      // Add the despawn waypoint
      private _despawnWP = _planeGroup addWaypoint [_despawnPos, 5];
      _despawnWP setWaypointCompletionRadius 10;
      _despawnWP setWaypointStatements
      ["true", "[this] execVM '\x\nfst\addons\modules\functions\fnc_moduleAirStrikeDoDespawn.sqf';"];

    };
    */
} forEach _planePositions;
