/*
_cfg = "true" configClasses (configFile >> "CfgWeapons");
for "_i" from 0 to ((count _cfg)-1) do
{
  if (isClass (_cfg select _i)) then
  {
    _cfgNam = configName (_cfg select _i);
    if (["bomb", _cfgNam] call BIS_fnc_inString) then
    {
		  _displayName = gettext (configfile >> "CfgWeapons" >> _cfgNam>> "displayName");
      _idx = lbAdd [_this, _displayName];
      lbSetData [_this, _idx, _cfgNam];
    };
  };
};
*/

params ["_bombCombo", "_planeType"];

lbClear _bombCombo;

_cfgVehicles = "true" configClasses (configFile >> "CfgVehicles");
for "_i" from 0 to ((count _cfgVehicles)-1) do
{
  if (isClass (_cfgVehicles select _i)) then
  {
    _vehicleCfgName = configName (_cfgVehicles select _i);
    _vehicleDisplayName  = gettext (configfile >> "CfgVehicles" >> _vehicleCfgName >> "displayName");

    if (_vehicleCfgName == _planeType) then
    {
      _getweapons = getArray (configfile >> "CfgVehicles" >> _vehicleCfgName >> "weapons");
      {
        if (["bomb", _x] call BIS_fnc_inString) then
        {
          _cfgWeapons = "true" configClasses (configFile >> "CfgWeapons");
          for "_i" from 0 to ((count _cfgWeapons)-1) do
          {
            if (isClass (_cfgWeapons select _i)) then
            {
              _weaponCfgName = configName (_cfgWeapons select _i);
              if (_weaponCfgName == "Bomb_04_Plane_CAS_01_F") then
              {
                _weaponDisplayName  = gettext (configfile >> "CfgWeapons" >> _weaponCfgName>> "displayName");
                _idx = lbAdd [_bombCombo, _weaponDisplayName];
                lbSetData [_bombCombo, _idx, _weaponDisplayName];
              };
            };
          };
        };
      } forEach _getweapons;
    };
  };
};
