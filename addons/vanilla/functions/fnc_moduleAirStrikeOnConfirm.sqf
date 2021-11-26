private _targetPos = uiNamespace getVariable "nfst_moduleAirStrikePos";

params ["_idcPlaneType", "_idcPlaneNumber", "_idcFormation", "_idcBombType", "_idcBombNumber", "_idcBombSpread", "_idcDropHeight", "_idcFlightSpeed", "_idcSpawnBearing", "_idcSpawnDistance", "_idcDespawnBearing", "_idcDespawnDistance", "_cooldown"];

private _planeType         = lbData [_idcPlaneType, lbCurSel _idcPlaneType];
private _formation         = lbData [_idcFormation, lbCursel _idcFormation];
private _bombType          = lbData [_idcBombType , lbCursel _idcBombType ];
private _planeNumber       = sliderPosition _idcPlaneNumber    ;
private _bombNumber        = sliderPosition _idcBombNumber     ;
private _bombSpread        = sliderPosition _idcBombSpread     ;
private _dropHeightATL     = sliderPosition _idcDropHeight     ;
private _flightSpeed       = sliderPosition _idcFlightSpeed    ;
private _bearingToSpawn    = sliderPosition _idcSpawnBearing   ;
private _distanceToSpawn   = sliderPosition _idcSpawnDistance  ;
private _bearingToDespawn  = sliderPosition _idcDespawnBearing ;
private _distanceToDespawn = sliderPosition _idcDespawnDistance;

closeDialog 0;

// Prepare some flight parameters
private _bearingToTarget  = (_bearingToSpawn + 180) % 360;
private _planeSpeedVector = [[-_flightSpeed / 3.6, 0, 0], _bearingToSpawn - 90, 2] call BIS_fnc_rotateVector3D;
private _flightHeightASL  = _dropHeightATL + getTerrainHeightASL _targetPos;
private _bombDropDistance = 500;

// Compute spawn, despawn and targets positions for all planes
private _centralSpawnPosition   = _targetPos getPos [_distanceToSpawn  , _bearingToSpawn  ];
private _centralDespawnPosition = _targetPos getPos [_distanceToDespawn, _bearingToDespawn];
private _spawnPositionOffsets   = [_formation, _planeNumber, _bearingToTarget ] call nfst_fnc_commonComputeFormationOffsets;
private _despawnPositionOffsets = [_formation, _planeNumber, _bearingToDespawn] call nfst_fnc_commonComputeFormationOffsets;
private _targetPositionOffsets  = [_formation, _planeNumber, _bearingToTarget, _bombSpread] call nfst_fnc_commonComputeTargetOffsets;
private _planePositions = [];
for "_i" from 0 to _planeNumber-1 do
{
  private _offsetReleasePosition = _targetPos getPos [_bombDropDistance, _bearingToSpawn];
  private _targetPositions = [];
  for "_j" from 0 to _bombNumber-1 do
  {
    private _offsetTargetPosition  = _targetPos getPos [_j * _bombSpread, _bearingToTarget];
    private _correctTargetPosition = _offsetTargetPosition vectorAdd (_targetPositionOffsets select _i);
    _targetPositions pushBack _correctTargetPosition;
  };

  _planePositions append
  [[
      _centralSpawnPosition   vectorAdd (_spawnPositionOffsets   select _i),
      _offsetReleasePosition  vectorAdd (_targetPositionOffsets  select _i),
      _centralDespawnPosition vectorAdd (_despawnPositionOffsets select _i),
      _targetPositions
  ]];
};

// Main loop
{
    _spawnPos   = _x select 0;
    _bombingPos = _x select 1;
    _despawnPos = _x select 2;
    _targetPositions = _x select 3;

    // Initialize the plane
    private _plane = _planeType createVehicle _spawnPos;
    [_plane, _flightHeightASL, _spawnPos] call BIS_fnc_setHeight;
    _plane setDir _bearingToTarget;
    _plane setVelocity _planeSpeedVector;
    _plane flyInHeightASL [_flightHeightASL, _flightHeightASL, _flightHeightASL];
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

    // Add bombing run waypoint
    private _bombingRunWP = _planeGroup addWaypoint [_bombingPos, -1];
    _bombingRunWP setWaypointCompletionRadius 10;
    _bombingRunWP setWaypointBehaviour "CARELESS";
    _bombingRunWP setWaypointStatements
    ["true", format ["[this, %1, %2, %3, %4] execVM '\x\nfst_zm\addons\vanilla\functions\fnc_moduleAirStrikeDoBombingRun.sqf';", str _activeWeapon, _targetPositions, _fireMode, _cooldown]];

    // Add bombing end waypoint
    private _bombingEndWP = _planeGroup addWaypoint [_targetPositions select ((count _targetPositions) - 1), -1];
    _bombingEndWP setWaypointCompletionRadius 10;

    // Add the despawn waypoint
    private _despawnWP = _planeGroup addWaypoint [_despawnPos, -1];
    _despawnWP setWaypointCompletionRadius 10;
    _despawnWP setWaypointStatements
    ["true", "[this] execVM '\x\nfst_zm\addons\vanilla\functions\fnc_moduleAirStrikeDoDespawn.sqf';"];

// Add objects to curators
/*
    if isServer then
    {
      {
        (getAssignedCuratorUnit _x) addCuratorEditableObjects
        [
          [_plane],
          true
        ];
        systemChat "Added";
      } forEach allCurators;
    };
*/
} forEach _planePositions;
