params ["_idcSplashRadiusSlider", "_idcSplashRadiusReadout", "_minSafeZone", "_maxSafeZone", "_idcSafeZoneSlider", "_idcSafeZoneReadout"];

private _newVal = sliderPosition _idcSplashRadiusSlider;

ctrlSetText [_idcSplashRadiusReadout, str _newVal];

if ( _newVal <= _maxSafeZone ) then
{
  sliderSetRange [_idcSafeZoneSlider, _minSafeZone, _newVal - 1];
  if ( _newVal <= (sliderPosition _idcSafeZoneSlider) ) then
  {
    _newSpread = _newVal - 1;
    sliderSetPosition [_idcSafeZoneSlider, _newSpread];
    ctrlSetText [_idcSafeZoneReadout, str _newSpread];
  };
}
else
{
  sliderSetRange [_idcSafeZoneSlider, _minSafeZone, _maxSafeZone];
};
