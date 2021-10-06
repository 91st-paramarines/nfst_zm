#include "script_component.hpp"

/*----------------------------------ARGUMENTS---------------------------------*/
private _spawnDistance   = sliderPosition 1900;
private _spawnBearing    = sliderPosition 1901;
private _despawnDistance = sliderPosition 1902;
private _despawnBearing  = sliderPosition 1903;
private _flightSpeed     = sliderPosition 1904;
flightAltitude           = sliderPosition 1905;
private _escortSize      = sliderPosition 1906;
private _logic           = param [0,objNull,[objNull]];

// ----- Future user inputs, for now hardcoded settings
crateType      = "AmmoCrate_NoInteractive_";
smokeType      = "SmokeShellPurple";
formationSpacing  = 100;
formationAperture = 120;
/*----------------------------------------------------------------------------*/

// Closing the GUI display
closeDialog 0;

/*------------------------COMMON FLIGHTS PARAMETERS---------------------------*/
if (_escortSize > 0) then
{
    _despawnBearing = (_spawnBearing + 180) % 360;
};

private _dropPos         = getPos _logic;
dropPosX                 = supplyDropPos select 0;
dropPosY                 = supplyDropPos select 1;
private _angleToSpawn    = 90 - _spawnBearing  ;
private _angleToDespawn  = 90 - _despawnBearing;

// ----- Compute flight vector
planeSpeedX = _flightSpeed * cos(_angleToSpawn+180);
planeSpeedY = _flightSpeed * sin(_angleToSpawn+180);
planeSpeedZ = 0;
planeSpeed = [planeSpeedX, planeSpeedY, planeSpeedZ];
/*----------------------------------------------------------------------------*/

/*--------------------------DROP PLANE FLIGHT PLAN----------------------------*/
// ----- Compute point offsets
spawnDeltaX   = _spawnDistance   * cos(_angleToSpawn  );
spawnDeltaY   = _spawnDistance   * sin(_angleToSpawn  );
despawnDeltaY = _despawnDistance * sin(_angleToDespawn);
despawnDeltaX = _despawnDistance * cos(_angleToDespawn);

// ----- Derive point coordinates
spawnPosX   = dropPosX + spawnDeltaX  ;
spawnPosY   = dropPosY + spawnDeltaY  ;
despawnPosX = dropPosX + despawnDeltaX;
despawnPosY = dropPosY + despawnDeltaY;
/*----------------------------------------------------------------------------*/

/*-------------------------ESCORT PLANES FLIGHT PLAN--------------------------*/
nfst_fnc_changeBase =
{
    params ["_x", "_y", "_t"];
    private _xt = _x * cos(_t) - _y * sin(_t);
    private _yt = _y * cos(_t) + _x * sin(_t);
    [_x, _y];
};

// ----- Computing escort planes relative offsets
private _frontPlaneRx       =  0;
private _frontPlaneRy       =  formationSpacing;
private _middlePlaneLeftRx  = -formationSpacing * sin(formationAperture/2);
private _middlePlaneLeftRy  = -formationSpacing * cos(formationAperture/2);
private _middlePlaneRightRx =  formationSpacing * sin(formationAperture/2);
private _middlePlaneRightRy = -formationSpacing * cos(formationAperture/2);
private _rearPlaneLeftRx    = -2 * formationSpacing * sin(formationAperture/2);
private _rearPlaneLeftRy    = -2 * formationSpacing * cos(formationAperture/2);
private _rearPlaneRightRx   =  2 * formationSpacing * sin(formationAperture/2);
private _rearPlaneRightRy   = -2 * formationSpacing * cos(formationAperture/2);

// ----- Computing escort planes general offsets for spawn and drop markers
private _frontPlaneGx1       = [_frontPlaneRx      , _frontPlaneRy      , _spawnBearing] call nfst_fnc_changeBase select 0;
private _frontPlaneGy1       = [_frontPlaneRx      , _frontPlaneRy      , _spawnBearing] call nfst_fnc_changeBase select 1;
private _middlePlaneLeftGx1  = [_middlePlaneLeftRx , _middlePlaneLeftRy , _spawnBearing] call nfst_fnc_changeBase select 0;
private _middlePlaneLeftGy1  = [_middlePlaneLeftRx , _middlePlaneLeftRy , _spawnBearing] call nfst_fnc_changeBase select 1;
private _middlePlaneRightGx1 = [_middlePlaneRightRx, _middlePlaneRightRy, _spawnBearing] call nfst_fnc_changeBase select 0;
private _middlePlaneRightGy1 = [_middlePlaneRightRx, _middlePlaneRightRy, _spawnBearing] call nfst_fnc_changeBase select 1;
private _rearPlaneLeftGx1    = [_rearPlaneLeftRx   , _rearPlaneLeftRy   , _spawnBearing] call nfst_fnc_changeBase select 0;
private _rearPlaneLeftGy1    = [_rearPlaneLeftRx   , _rearPlaneLeftRy   , _spawnBearing] call nfst_fnc_changeBase select 1;
private _rearPlaneRightGx1   = [_rearPlaneRightRx  , _rearPlaneRightRy  , _spawnBearing] call nfst_fnc_changeBase select 0;
private _rearPlaneRightGy1   = [_rearPlaneRightRx  , _rearPlaneRightRy  , _spawnBearing] call nfst_fnc_changeBase select 1;

// ----- Computing escort planes general offsets for despawn marker
private _frontPlaneGx2       = [_frontPlaneRx      , _frontPlaneRy      , _spawnBearing] call nfst_fnc_changeBase select 0;
private _frontPlaneGy2       = [_frontPlaneRx      , _frontPlaneRy      , _spawnBearing] call nfst_fnc_changeBase select 1;
private _middlePlaneLeftGx2  = [_middlePlaneLeftRx , _middlePlaneLeftRy , _spawnBearing] call nfst_fnc_changeBase select 0;
private _middlePlaneLeftGy2  = [_middlePlaneLeftRx , _middlePlaneLeftRy , _spawnBearing] call nfst_fnc_changeBase select 1;
private _middlePlaneRightGx2 = [_middlePlaneRightRx, _middlePlaneRightRy, _spawnBearing] call nfst_fnc_changeBase select 0;
private _middlePlaneRightGy2 = [_middlePlaneRightRx, _middlePlaneRightRy, _spawnBearing] call nfst_fnc_changeBase select 1;
private _rearPlaneLeftGx2    = [_rearPlaneLeftRx   , _rearPlaneLeftRy   , _spawnBearing] call nfst_fnc_changeBase select 0;
private _rearPlaneLeftGy2    = [_rearPlaneLeftRx   , _rearPlaneLeftRy   , _spawnBearing] call nfst_fnc_changeBase select 1;
private _rearPlaneRightGx2   = [_rearPlaneRightRx  , _rearPlaneRightRy  , _spawnBearing] call nfst_fnc_changeBase select 0;
private _rearPlaneRightGy2   = [_rearPlaneRightRx  , _rearPlaneRightRy  , _spawnBearing] call nfst_fnc_changeBase select 1;

// ----- Computing escort planes spawn positions
private _frontPlaneSpawn       = [spawnPosX + _frontPlaneGx1      , spawnPosY + _frontPlaneGy1      , flightAltitude];
private _middlePlaneLeftSpawn  = [spawnPosX + _middlePlaneLeftGx1 , spawnPosY + _middlePlaneLeftGy1 , flightAltitude];
private _middlePlaneRightSpawn = [spawnPosX + _middlePlaneRightGx1, spawnPosY + _middlePlaneRightGy1, flightAltitude];
private _rearPlaneRightSpawn   = [spawnPosX + _rearPlaneRightGx1  , spawnPosY + _rearPlaneRightGy1  , flightAltitude];
private _rearPlaneLeftSpawn    = [spawnPosX + _rearPlaneLeftGx1   , spawnPosY + _rearPlaneLeftGy1   , flightAltitude];

// ----- Computing escort planes drop positions
private _frontPlaneDrop       = [dropPosX + _frontPlaneGx1      , dropPosY + _frontPlaneGy1      , flightAltitude];
private _middlePlaneLeftDrop  = [dropPosX + _middlePlaneLeftGx1 , dropPosY + _middlePlaneLeftGy1 , flightAltitude];
private _middlePlaneRightDrop = [dropPosX + _middlePlaneRightGx1, dropPosY + _middlePlaneRightGy1, flightAltitude];
private _rearPlaneLeftDrop    = [dropPosX + _rearPlaneLeftGx1   , dropPosY + _rearPlaneLeftGy1   , flightAltitude];
private _rearPlaneRightDrop   = [dropPosX + _rearPlaneRightGx1  , dropPosY + _rearPlaneRightGy1  , flightAltitude];

// ----- Computing escort planes despawn positions
private _frontPlaneDespawn       = [despawnPosX + _frontPlaneGx2      , despawnPosY + _frontPlaneGy2      , flightAltitude];
private _middlePlaneLeftDespawn  = [despawnPosX + _middlePlaneLeftGx2 , despawnPosY + _middlePlaneLeftGy2 , flightAltitude];
private _middlePlaneRightDespawn = [despawnPosX + _middlePlaneRightGx2, despawnPosY + _middlePlaneRightGy2, flightAltitude];
private _rearPlaneLeftDespawn    = [despawnPosX + _rearPlaneLeftGx2   , despawnPosY + _rearPlaneLeftGy2   , flightAltitude];
private _rearPlaneRightDespawn   = [despawnPosX + _rearPlaneRightGx2  , despawnPosY + _rearPlaneRightGy2  , flightAltitude];

// ----- Packaging all that
private _escortPlanesSpawn     = [_frontPlaneSpawn  , _middlePlaneLeftSpawn  , _middlePlaneRightSpawn  , _rearPlaneLeftSpawn  , _rearPlaneRightSpawn  ];
private _escortPlanesDrop      = [_frontPlaneDrop   , _middlePlaneLeftDrop   , _middlePlaneRightDrop   , _rearPlaneLeftDrop   , _rearPlaneRightDrop   ];
private _escortPlanesDespawn   = [_frontPlaneDespawn, _middlePlaneLeftDespawn, _middlePlaneRightDespawn, _rearPlaneLeftDespawn, _rearPlaneRightDespawn];
private _escortPlanesPositions = [_escortPlanesSpawn, _escortPlanesDrop, _escortPlanesDespawn];
/*----------------------------------------------------------------------------*/

systemChat format ["Module position is:%1", supplyDropPos   ];
/*------------------------------------DEBUG-------------------------------------
systemChat format ["Spawn distance    :%1", _spawnDistance  ];
systemChat format ["Spawn bearing     :%1", _spawnBearing   ];
systemChat format ["Despawn distance  :%1", _despawnDistance];
systemChat format ["Despawn bearing   :%1", _despawnBearing ];
systemChat format ["Flight speed      :%1", _flightSpeed    ];
systemChat format ["Flight altitude   :%1", flightAltitude  ];
systemChat format ["Escort size       :%1", _escortSize     ];
systemChat format ["dropPosX          :%1", dropPosX        ];
systemChat format ["dropPosY          :%1", dropPosY        ];
systemChat format ["spawnDeltaX       :%1", spawnDeltaX     ];
systemChat format ["spawnDeltaY       :%1", spawnDeltaY     ];
systemChat format ["despawnDeltaX     :%1", despawnDeltaX   ];
systemChat format ["despawnDeltaY     :%1", despawnDeltaY   ];
systemChat format ["planeSpeedX       :%1", planeSpeedX     ];
systemChat format ["planeSpeedY       :%1", planeSpeedY     ];

systemChat format ["_frontPlaneRx       :%1",_frontPlaneRx       ];
systemChat format ["_frontPlaneRy       :%1",_frontPlaneRy       ];
systemChat format ["_middlePlaneLeftRx  :%1",_middlePlaneLeftRx  ];
systemChat format ["_middlePlaneLeftRy  :%1",_middlePlaneLeftRy  ];
systemChat format ["_middlePlaneRightRx :%1",_middlePlaneRightRx ];
systemChat format ["_middlePlaneRightRy :%1",_middlePlaneRightRy ];
systemChat format ["_rearPlaneLeftRx    :%1",_rearPlaneLeftRx    ];
systemChat format ["_rearPlaneLeftRy    :%1",_rearPlaneLeftRy    ];
systemChat format ["_rearPlaneRightRx   :%1",_rearPlaneRightRx   ];
systemChat format ["_rearPlaneRightRy   :%1",_rearPlaneRightRy   ];
systemChat format ["_frontPlaneGx1      :%1",_frontPlaneGx1      ];
systemChat format ["_frontPlaneGy1      :%1",_frontPlaneGy1      ];
systemChat format ["_middlePlaneLeftGx1 :%1",_middlePlaneLeftGx1 ];
systemChat format ["_middlePlaneLeftGy1 :%1",_middlePlaneLeftGy1 ];
systemChat format ["_middlePlaneRightGx1:%1",_middlePlaneRightGx1];
systemChat format ["_middlePlaneRightGy1:%1",_middlePlaneRightGy1];
systemChat format ["_rearPlaneLeftGx1   :%1",_rearPlaneLeftGx1   ];
systemChat format ["_rearPlaneLeftGy1   :%1",_rearPlaneLeftGy1   ];
systemChat format ["_rearPlaneRightGx1  :%1",_rearPlaneRightGx1  ];
systemChat format ["_rearPlaneRightGy1  :%1",_rearPlaneRightGy1  ];
------------------------------------------------------------------------------*/


/*---------------------------------DROP PLANE---------------------------------*/
// ----- Object creation and initialization
private _planeSpawn = [spawnPosX, spawnPosY, flightAltitude];
plane = "B_Plane_CAS_01_F" createVehicle _planeSpawn;
systemChat (str _planeSpawn);
[plane, flightAltitude, _planeSpawn, "ATL"] call BIS_fnc_setHeight;
plane setDir (_spawnBearing + 180);
plane setVelocity planeSpeed;
plane flyInHeight flightAltitude;
plane forceSpeed (_flightSpeed * 1000 / 3600);

// ----- Adding AI
private _planeGroup = createVehicleCrew plane;
driver plane disableAI "FSM";


// ----- Adding first waypoint (drop point)
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

// ----- Adding second waypoint (RTB)
private _waypointRtbPos = [despawnPosX, despawnPosY, flightAltitude];
private _waypointRtb    = _planeGroup addWaypoint [_waypointRtbPos, 1];

_waypointRtb setWaypointStatements
["true", "
{plane deleteVehicleCrew _x} forEach crew plane;
deleteVehicle plane;
"];

//plane setVelocityTransformation [ATLtoASL _planeSpawn, ATLtoASL _waypointDzPos, planeSpeed, planeSpeed, VectorDir plane, VectorDir plane, VectorUp plane, VectorUp plane, 0.5];

/*----------------------------------------------------------------------------*/

/*--------------------------------ESCORT PLANE--------------------------------*/
private _even = 1 - _escortSize % 2;
for [{private _i = _even}, {_i < _escortSize + _even}, {_i = _i + 1}] do
{
    // ----- Object creation and initialization
    _planeSpawn = _escortPlanesPositions select 0 select _i;
    private _plane = "B_Plane_Fighter_02_F" createVehicle _planeSpawn;
    [_plane, flightAltitude, _planeSpawn, "ATL"] call BIS_fnc_setHeight;
    //_plane setDir (_spawnBearing + 180);
    _plane setVelocity planeSpeed;
    //_plane flyInHeight flightAltitude;
    _plane attachTo [plane];





    // ----- Adding AI
    private _escortPlaneGroup = createVehicleCrew _plane;
    driver _plane disableAI "FSM";
/*
    // ----- Adding first waypoint (drop point)
    private _waypointDzPos = _escortPlanesPositions select 1 select _i;
    private _waypointDz    = _planeGroup addWaypoint [_waypointDzPos, 1];

    _waypointDz setWaypointCompletionRadius 1;
    */

    // ----- Adding second waypoint (RTB)
    private _waypointRtbPos = _escortPlanesPositions select 2 select _i;
    private _waypointRtb    = _planeGroup addWaypoint [_waypointRtbPos, 1];

    _waypointRtb setWaypointStatements
    ["true", "
    _plane = vehicle this;
    {_plane deleteVehicleCrew _x} forEach crew _plane;
    deleteVehicle _plane;
    "];
};
/*----------------------------------------------------------------------------*/


true;
