params ["_idcPlanesCombo"];

private _bombCarryingPlanes = missionNamespace getVariable "nfst_moduleAirStrikeBomberPlanes";

{
  _idx = lbAdd [_idcPlanesCombo, _x select 1];
  lbSetData [_idcPlanesCombo, _idx, _x select 0];
} forEach _bombCarryingPlanes;
