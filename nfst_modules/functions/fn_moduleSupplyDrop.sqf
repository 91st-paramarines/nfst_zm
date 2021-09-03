private _spawnDistance   = sliderPosition 1900;
private _spawnBearing    = sliderPosition 1901;
private _despawnDistance = sliderPosition 1902;
private _despawnBearing  = sliderPosition 1903;
private _flightSpeed     = sliderPosition 1904;
private _flightAltitude  = sliderPosition 1905;
private _hasEscort       = cbChecked ((findDisplay 9100) displayCtrl 2800);
private _escortSize      = sliderPosition 1906;
private _logic           = param [0,objNull,[objNull]];
private _dropPos         = getPos _logic;

systemChat "Received a supply drop request";
systemChat format ["Spawn distance    :%1", _spawnDistance  ];
systemChat format ["Spawn bearing     :%1", _spawnBearing   ];
systemChat format ["Despawn distance  :%1", _despawnDistance];
systemChat format ["Despawn bearing   :%1", _despawnBearing ];
systemChat format ["Flight speed      :%1", _flightSpeed    ];
systemChat format ["Flight altitude   :%1", _flightAltitude ];
systemChat format ["Has escort        :%1", _hasEscort      ];
systemChat format ["Escort size       :%1", _escortSize     ];
systemChat format ["Module position is:%1", _dropPos        ];

// Parameters of the drop
spawnOffsetX   = 0;
spawnOffsetY   = -5000;
altitudeATL    = 200;
planeSpeedX    = 0;
planeSpeedY    = 100;
planeSpeedZ    = 0;
despawnOffsetX = -2000;
despawnOffsetY = -5000;
crateType      = "AmmoCrate_NoInteractive_";
smokeType      = "SmokeShellPurple";

// Retrieving data from the module
_logic = param [0,objNull,[objNull]]; // Argument 0 is module logic

///_units = param [1,[],[[]]]; // Argument 1 is list of affected units (affected by value selected in the 'class Units' argument))

// True when the module was activated, false when it is deactivated (i.e., synced triggers are no longer active)
///_activated = param [2,true,[true]];

// Module specific behavior. Function can extract arguments from logic and use them.
///if (_activated) then {
///	 // Attribute values are saved in module's object space under their class names
///	 _bombYield = _logic getVariable ["Yield",-1]; // (as per the previous example, but you can define your own.)
///	 hint format ["Bomb yield is: %1", _bombYield ]; // will display the bomb yield, once the game is started
///};
// Module function is executed by spawn command, so returned value is not necessary, but it is good practice.


private _markerPos  = getPos _logic;
systemChat str _markerPos;
private _markerX    = _markerPos select 0;
private _markerY    = _markerPos select 1;

private _planeSpawn = [_markerX + spawnOffsetX, _markerY + spawnOffsetY, altitudeATL];

plane = "LIB_C47_Skytrain" createVehicle _planeSpawn;
[plane, altitudeATL, _planeSpawn, "ATL"] call BIS_fnc_setHeight;
plane setVelocity [planeSpeedX, planeSpeedY, planeSpeedZ];
plane flyInHeight altitudeATL;
private _planeGroup = createVehicleCrew plane;
driver plane disableAI "FSM";

private _waypointDzPos = [_markerX, _markerY, altitudeATL];
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

private _waypointRtbPos = [_markerX + despawnOffsetX, _markerY + despawnOffsetY, altitudeATL];
private _waypointRtb    = _planeGroup addWaypoint [_waypointRtbPos, 1];

_waypointRtb setWaypointStatements
["true", "
{plane deleteVehicleCrew _x} forEach crew plane;
deleteVehicle plane;
"];

true;
