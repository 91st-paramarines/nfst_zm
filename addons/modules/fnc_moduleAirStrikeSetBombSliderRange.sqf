private _bombsNumberSlider = 1901;
private _plane = lbData [2100, lbCurSel 2100];
private _bombMagazine = lbData [2102, lbCurSel 2102];

private _compatibleBombs = missionNamespace getVariable "nfst_moduleAirStrikeBomberPlanes";

_totalMountableBombs = 0;
{
  if ((_x select 0) == _plane) then
  {
    _planePylons = _x select 3;
    {
      _pylonMagazines = _x select 1;
      {
        if ((_x select 0) == _bombMagazine) then
        {
          _totalMountableBombs = _totalMountableBombs + (_x select 1);
        };
      } forEach _pylonMagazines;
    } forEach _planePylons;
  };
} forEach _compatibleBombs;

sliderSetRange [_bombsNumberSlider, 0, _totalMountableBombs];
