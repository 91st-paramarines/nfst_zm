params ["_bombsCombo", "_plane"];

private _compatibleBombs = missionNamespace getVariable "nfst_moduleAirStrikeBomberPlanes";

ctrlEnable [_bombsCombo, true];

{
  if ((_x select 0) == _plane) then
  {
    systemChat "Hoodlida";
    _bombsInfo = _x select 2;
    {
      systemChat str _x;
      _idx = lbAdd [_bombsCombo, _x select 1];
      systemChat str _idx;
      lbSetData [_bombsCombo, _idx, _x select 0];
    } forEach _bombsInfo;
  };
} forEach _compatibleBombs;
