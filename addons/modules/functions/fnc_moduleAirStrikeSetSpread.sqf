params ["_idcSpeedSlider", "_idcSpeedReadout", "_idcSpreadSlider", "_idcSpreadReadout", "_cooldown"];

private _curSpeed  = sliderPosition _idcSpeedSlider;
private _maxSpeed  = (sliderRange _idcSpeedSlider) select 1;
private _curSpread = sliderPosition _idcSpreadSlider;

ctrlSetText [_idcSpeedReadout, str _curSpeed];

private _minSpread = round (_curSpeed * _cooldown / 3.6);
private _maxSpread = round (_maxSpeed * _cooldown / 3.6);

sliderSetRange [_idcSpreadSlider, _minSpread, _maxSpread];

if (_curSpread < _minSpread) then
{
  sliderSetPosition [_idcSpreadSlider, _minSpread];
  ctrlSetText [_idcSpreadReadout, str _minSpread];
}
