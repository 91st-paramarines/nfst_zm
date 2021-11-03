params ["_x", "_y", "_t"];
private _xt = _x * cos(_t) + _y * sin(_t);
private _yt = _y * cos(_t) - _x * sin(_t);
[_xt, _yt];
