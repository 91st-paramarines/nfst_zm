private _bombsCombo  = 2102;
private _speedSlider = 1904;
private _plane = lbData [2100, lbCurSel 2100];

private _compatibleBombs = missionNamespace getVariable "nfst_moduleAirStrikeBomberPlanes";

ctrlEnable [_bombsCombo, true];
lbClear _bombsCombo;

{
  if ((_x select 0) == _plane) then
  {
    _stallSpeed = _x select 4;
    _maxSpeed   = _x select 5;
    ctrlShow [_speedSlider, true];
    sliderSetRange [_speedSlider, _stallSpeed, _maxSpeed];

    _bombsInfo  = _x select 2;
    {
      _idx = lbAdd [_bombsCombo, _x select 1];
      lbSetData [_bombsCombo, _idx, _x select 0];
    } forEach _bombsInfo;
  };
} forEach _compatibleBombs;
