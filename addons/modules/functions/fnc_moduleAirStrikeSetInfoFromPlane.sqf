params ["_idcPlaneType", "_idcBombsCombo", "_idcBombsSlider", "_idcBombsReadout", "_idcSpeedSlider", "_idcSpeedReadout", "_idcSpreadSlider", "_idcSpreadReadout", "_cooldown"];

private _planeType = lbData [_idcPlaneType, lbCurSel _idcPlaneType];
private _compatibleBombs = missionNamespace getVariable "nfst_moduleAirStrikeBomberPlanes";

lbClear _idcBombsCombo;
lbSetCurSel [_idcBombsCombo, -1];

sliderSetPosition [_idcBombsSlider, 0];
sliderSetRange [_idcBombsSlider, 0, 0];
ctrlSetText [_idcBombsReadout, "0"];

{
  if ((_x select 0) == _planeType) then
  {
    _stallSpeed = _x select 4;
    _maxSpeed   = _x select 5;

    _defaultSpeed = round ((_stallSpeed + _maxSpeed) / 4);

    sliderSetRange [_idcSpeedSlider, _stallSpeed, _maxSpeed];
    sliderSetPosition [_idcSpeedSlider, _defaultSpeed];
    ctrlSetText [_idcSpeedReadout, str _defaultSpeed];

    _minSpread = round (_defaultSpeed * _cooldown / 3.6);
    _maxSpread = round (_maxSpeed  * _cooldown / 3.6);
    sliderSetRange [_idcSpreadSlider, _minSpread, _maxSpread];
    sliderSetPosition [_idcSpreadSlider, _minSpread];
    ctrlSetText [_idcSpreadReadout, str _minSpread];

    _bombsInfo  = _x select 2;
    {
      _idx = lbAdd [_idcBombsCombo, _x select 1];
      lbSetData [_idcBombsCombo, _idx, _x select 0];
    } forEach _bombsInfo;
  };
} forEach _compatibleBombs;
