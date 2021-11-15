params ["_groupLeader", "_activeWeapon", "_targets", "_fireMode" , "_cooldown"];

private _plane = vehicle _groupLeader;
_planeSide = side _plane;
private _targetType = if (_planeSide getfriend west > 0.6) then {"LaserTargetW"} else {"LaserTargetE"};
private _fired = false;
private _planeDriver = driver _plane;
private _planeGunner = gunner _plane;

{
  _target = createvehicle [_targetType, _x, [], 0, "none"];
  _jeep = createvehicle ["C_Van_01_fuel_F", _x, [], 0, "none"];
  _plane reveal lasertarget _target;
  _plane dowatch lasertarget _target;
  _plane dotarget lasertarget _target;

  _fired = _planeDriver fireattarget [_target, _activeWeapon];

  if (!_fired) then
  {
    _fired = _planeGunner fireattarget [_target, _activeWeapon];
  };

  _plane forgetTarget lasertarget _target;
  _plane dowatch objNull;
  deleteVehicle _target;
  sleep(_cooldown);
} forEach _targets;

/*
for "_i" from 1 to (_bombNumber) do
{
  (gunner _plane) forceWeaponFire [_activeWeapon, _fireMode];
  (driver _plane) forceWeaponFire [_activeWeapon, _fireMode];
  uiSleep(_bombDelay);
};
*/
