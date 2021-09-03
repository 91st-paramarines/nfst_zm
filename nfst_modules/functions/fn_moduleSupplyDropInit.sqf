// Recovering input data
private _spawnDistance   = sliderPosition 1900;
private _spawnBearing    = sliderPosition 1901;
private _despawnDistance = sliderPosition 1902;
private _despawnBearing  = sliderPosition 1903;
private _flightSpeed     = sliderPosition 1904;
flightAltitude  = sliderPosition 1905;
private _hasEscort       = cbChecked ((findDisplay 9100) displayCtrl 2800);
private _escortSize      = sliderPosition 1906;
private _logic           = param [0,objNull,[objNull]];
private _dropPos         = getPos _logic;

// DEBUG

systemChat "Received a supply drop request";
systemChat format ["Spawn distance    :%1", _spawnDistance  ];
systemChat format ["Spawn bearing     :%1", _spawnBearing   ];
systemChat format ["Despawn distance  :%1", _despawnDistance];
systemChat format ["Despawn bearing   :%1", _despawnBearing ];
systemChat format ["Flight speed      :%1", _flightSpeed    ];
systemChat format ["Flight altitude   :%1", flightAltitude  ];
systemChat format ["Has escort        :%1", _hasEscort      ];
systemChat format ["Escort size       :%1", _escortSize     ];
systemChat format ["Module position is:%1", supplyDropPos   ];


// Parse input data
dropPosX = supplyDropPos select 0;
dropPosY = supplyDropPos select 1;
private _angleToSpawn   = 90 - _spawnBearing  ;
private _angleToDespawn = 90 - _despawnBearing;
systemChat format ["dropPosX :%1", dropPosX];
systemChat format ["dropPosY :%1", dropPosY];


spawnDeltaX   = _spawnDistance   * cos(_angleToSpawn  );
spawnDeltaY   = _spawnDistance   * sin(_angleToSpawn  );
despawnDeltaY = _despawnDistance * sin(_angleToDespawn);
despawnDeltaX = _despawnDistance * cos(_angleToDespawn);
systemChat format ["spawnDeltaX :%1", spawnDeltaX];
systemChat format ["spawnDeltaY :%1", spawnDeltaY];
systemChat format ["despawnDeltaX :%1", despawnDeltaX];
systemChat format ["despawnDeltaY :%1", despawnDeltaY];

spawnX   = dropPosX + spawnDeltaX  ;
spawnY   = dropPosY + spawnDeltaY  ;
despawnX = dropPosX + despawnDeltaX;
despawnY = dropPosY + despawnDeltaY;

planeSpeedX = _flightSpeed * cos(_angleToSpawn+180);
planeSpeedY = _flightSpeed * sin(_angleToSpawn+180);
planeSpeedZ = 0;
systemChat format ["planeSpeedX :%1", planeSpeedX];
systemChat format ["planeSpeedY :%1", planeSpeedY];

crateType      = "AmmoCrate_NoInteractive_";
smokeType      = "SmokeShellPurple";

private _planeSpawn = [spawnX, spawnY, flightAltitude];

plane = "LIB_C47_Skytrain" createVehicle _planeSpawn;
[plane, flightAltitude, _planeSpawn, "ATL"] call BIS_fnc_setHeight;
plane setDir (_spawnBearing + 180);
plane setVelocity [planeSpeedX, planeSpeedY, planeSpeedZ];
plane flyInHeight flightAltitude;
private _planeGroup = createVehicleCrew plane;
driver plane disableAI "FSM";

private _waypointDzPos = [dropPosX, dropPosY, flightAltitude];
private _waypointDz    = _planeGroup addWaypoint [_waypointDzPos, 1];

_waypointDz setWaypointCompletionRadius 1;
_waypointDz setWaypointStatements
["true", "
[] spawn
{
 private _speedVector = velocity plane;
 private _speedX = _speedVector select 0;
 private _speedY = _speedVector select 1;
 private _speedPlanar = sqrt (_speedX * _speedX + _speedY * _speedY);
 private _underShoot  = 100;
 private _napTime     = round (_underShoot / _speedPlanar);
 sleep _napTime;

 private _dropPos    = getPos plane;
 private _dropHeight = _dropPos select 2;
 private _parachute  = 'B_Parachute_02_F' createVehicle _dropPos;
 [_parachute, _dropHeight, _dropPos, 'ATL'] call BIS_fnc_setHeight;

 private _crate = crateType createVehicle _dropPos;
 ['AmmoboxInit', [_crate, true]] call BIS_fnc_arsenal;
 _crate attachTo [_parachute, [0, 0, 0]];
 systemChat format['%1', velocity _crate select 2];

 private _smokeType = smokeType;
 [_crate, _parachute, _smokeType] spawn
 {
  params ['_crate', '_parachute', '_smokeType'];
  waitUntil {
   getPos _crate select 2 < 1 || isNull _parachute
  };

  detach _crate;
  [_crate, 0, getPos _crate, 'ATL'] call BIS_fnc_setHeight;
  _smokeType createVehicle [getPos _crate select 0, getPos _crate select 1, 5];
 };
};
"];

private _waypointRtbPos = [despawnX, despawnY, flightAltitude];
private _waypointRtb    = _planeGroup addWaypoint [_waypointRtbPos, 1];

_waypointRtb setWaypointStatements
["true", "
{plane deleteVehicleCrew _x} forEach crew plane;
deleteVehicle plane;
"];

true;
