
  params ["_groupLeader", "_activeWeapon", "_targetPos", "_bearingToTarget", "_planeSpeedVector", "_flightHeight", "_flightSpeed"];

  private _plane = vehicle _groupLeader;
  _planeSide = side _plane;

  private _targetType = if (_planeSide getfriend west > 0.6) then {"LaserTargetW"} else {"LaserTargetE"};
  _target = createvehicle [_targetType, _targetPos, [], 0, "none"];

  _plane reveal lasertarget _target;
  _plane dowatch lasertarget _target;
  _plane dotarget lasertarget _target;

  _planeDriver = driver _plane;
  _planeDriver fireattarget [_target, _activeWeapon];

  _plane forgetTarget lasertarget _target;
  _plane dowatch objNull;
  deleteVehicle _target;

  _plane flyInHeightASL [_flightHeight, _flightHeight, _flightHeight];
  _plane limitSpeed _flightSpeed;
