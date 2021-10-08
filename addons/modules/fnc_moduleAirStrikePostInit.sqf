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

private _spawnDeltaX   = _spawnDistance   * cos(_angleToSpawn  );
private _spawnDeltaY   = _spawnDistance   * sin(_angleToSpawn  );
private _despawnDeltaY = _despawnDistance * sin(_angleToDespawn);
private _despawnDeltaX = _despawnDistance * cos(_angleToDespawn);

private _targetX = _targetPos select 0;
private _targetY = _targetPos select 1;

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
  _despawnPos = [_despawnPosX + _offsetDespawnX, _despawnPosY + _offsetDespawnY, 0];

  _planePositions append [[_spawnPos, _bombingPos, _despawnPos]];
};


// 4
private _planeSpeedX = _flightSpeed * cos(_angleToSpawn+180);
private _planeSpeedY = _flightSpeed * sin(_angleToSpawn+180);
private _planeSpeedZ = 0;
private _planeSpeedVector = [_planeSpeedX, _planeSpeedY, _planeSpeedZ];

{
    _spawnPos   = _x select 0;
    _bombingPos = _x select 1;
    _despawnPos = _x select 2;
    private _plane = _planeType createVehicle _spawnPos;
    [_plane, _flightHeight, _spawnPos, "ATL"] call BIS_fnc_setHeight;
    _plane setDir _bearingToTarget;
    _plane setVelocity _planeSpeedVector;
    _plane flyInHeight _flightHeight;

    private _planeGroup = createVehicleCrew _plane;
    driver _plane disableAI "FSM";

    private _bombingWP = _planeGroup addWaypoint [_bombingPos, 1];
    _bombingWP setWaypointCompletionRadius 10;
    _bombingWP setWaypointStatements
    ["true", format ["[this, %1, %2, %3, %4] execVM '\x\nfst\addons\modules\fnc_moduleAirStrikeDoBombingRun.sqf';", str _bombType, _bombNumber, _bombDelay, _flightHeight]];


} forEach _planePositions;
