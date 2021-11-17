params ["_idcPlaneType", "_idcBombType", "_idcbombsNumberSlider", "_idcBombsNumberHeader"];

private _planeType    = lbData [_idcPlaneType, lbCurSel _idcPlaneType];
private _bombMagazine = lbData [_idcBombType , lbCurSel _idcBombType ];

private _compatibleBombs = missionNamespace getVariable "nfst_moduleAirStrikeBomberPlanes";

_totalMountableBombs = 0;
{
  if ((_x select 0) == _planeType) then
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

sliderSetPosition [_idcBombsNumberSlider, 0];
sliderSetRange [_idcBombsNumberSlider, 0, _totalMountableBombs];
ctrlSetText [_idcBombsNumberHeader, "0"];
