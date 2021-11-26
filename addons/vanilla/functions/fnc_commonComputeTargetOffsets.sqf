params["_formation", "_planeNumber", "_bearing", "_spread"];

private _formationSpacing = 150;

if (_planeNumber <= 0) then {throw "Number of planes in formation must be at least one."};

switch (_formation) do
{
  case "Wedge" : {
    [_formation, _planeNumber, _bearingToTarget ] call nfst_fnc_commonComputeFormationOffsets
  };
  case "Line"  : {
    [_formation, _planeNumber, _bearingToTarget ] call nfst_fnc_commonComputeFormationOffsets
  };
  case "Column": {
    _firstTarget = [0, 0, 0];

    private _offsets = []; // The first plane in the formation has no offset
    private _delta = _spread / _planeNumber;

    for "_i" from 0 to _planeNumber-1 do
    {
      _offset = _firstTarget getPos [_delta * _i, _bearing];
      _offsets pushBack _offset;
    };
    _offsets
  };
  default {throw "Unknown formation."};
};
