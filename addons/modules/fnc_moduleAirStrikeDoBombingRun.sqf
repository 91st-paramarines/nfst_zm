params ["_groupLeader", "_bombNumber", "_bombDelay", "_activeWeapon", "_fireMode"];

private _plane = vehicle _groupLeader;

for "_i" from 1 to (_bombNumber) do
{
  (gunner _plane) forceWeaponFire [_activeWeapon, _fireMode];
  (driver _plane) forceWeaponFire [_activeWeapon, _fireMode];
  uiSleep(_bombDelay);
};
