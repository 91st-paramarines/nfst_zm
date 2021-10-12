params ["_groupLeader"];

private _plane = vehicle _groupLeader;

{
  _plane deleteVehicleCrew _x;
} forEach crew _plane;
deleteVehicle _plane;
