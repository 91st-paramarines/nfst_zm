params["_formation", "_planeNumber", "_bearing"];

private _formationSpacing = 150;

if (_planeNumber <= 0) then {throw "Number of planes in formation must be at least one."};

private _offsetPlusX  = 0;
private _offsetMinusX = 0;
private _offsetMinusY = 0;
private _isColumn     = 0;

switch (_formation) do
{
  case "Wedge" : {
    _offsetPlusX  =  _formationSpacing * cos(45);
    _offsetMinusX = -_formationSpacing * cos(45);
    _offsetMinusY = -_formationSpacing * sin(45);
  };
  case "Column": {
    _isColumn     = 1;
    _offsetPlusX  = 0;
    _offsetMinusX = 0;
    _offsetMinusY = -_formationSpacing;
  };
  case "Line"  : {
    _offsetPlusX  =  _formationSpacing;
    _offsetMinusX = -_formationSpacing;
    _offsetMinusY = 0;
  };
  default {throw "Unknown formation."};
};

private _offsets = [[0, 0, 0]]; // The first plane in the formation has no offset
private _offsetX = 0;
private _offsetY = 0;
private _rebased = [];

for "_i" from 2 to (_planeNumber) do
{
  if (_i%2 == 0) then
  {
    _offsetX = _i/2 * _offsetPlusX;
    _offsetY = _i/2 * _offsetMinusY * (1 - _isColumn) + _isColumn * (_i-1) * _offsetMinusY;
  }
  else
  {
    _offsetX = (_i-1)/2 * _offsetMinusX;
    _offsetY = (_i-1)/2 * _offsetMinusY * (1 - _isColumn) + _isColumn * (_i-1) * _offsetMinusY;
  };

  _rebased = [_offsetX, _offsetY, _bearing] call nfst_fnc_commonRebase2D;
  _offsetX = _rebased select 0;
  _offsetY = _rebased select 1;

  _offsets append [[_offsetX, _offsetY, 0]];
};

_offsets;
