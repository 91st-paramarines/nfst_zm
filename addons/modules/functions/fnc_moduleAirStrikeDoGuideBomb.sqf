_projectile = _this;

_dt = 0.05;
_g  = 98.1;
while {alive _projectile} do
{
  //systemChat str ((vectorMagnitude velocity _projectile) * 3.6);
  uiSleep(_dt);
};
