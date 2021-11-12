params ["_plane", "_projectile"];

private _speedX = (velocity _plane) select 0;
private _speedY = (velocity _plane) select 1;
private _speedZ = -10;

_dt = 0.05;
while {alive _projectile} do
{
  _projectile setVelocity [_speedX, _speedY, _speedZ];
  uiSleep(_dt);
};
