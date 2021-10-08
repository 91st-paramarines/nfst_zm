params ["_groupLeader", "_bombType", "_bombNumber", "_bombDelay", "_altitude"];

private _plane = vehicle _groupLeader;
private _planePos = [];
private _planeSpd = [];

systemChat str _bombType;

 for "_i" from 1 to _bombNumber do
 {
   _planePos = getPos _plane;
   _planeSpd = velocity _plane;

   _bomb = _bombType createVehicle _planePos;
   systemChat "Drop";
   [_bomb, _altitude, _planePos, "ATL"] call BIS_fnc_setHeight;

   uiSleep(_bombDelay);
 };
