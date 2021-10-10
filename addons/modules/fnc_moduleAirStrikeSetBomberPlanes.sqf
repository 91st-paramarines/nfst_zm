params ["_planesCombo"];

private _bombCarryingPlanes = missionNamespace getVariable "nfst_moduleAirStrikeBomberPlanes";

{
  _idx = lbAdd [_planesCombo, _x select 1];
  lbSetData [_planesCombo, _idx, _x select 0];
} forEach _bombCarryingPlanes; // TODO : Unknown variable
