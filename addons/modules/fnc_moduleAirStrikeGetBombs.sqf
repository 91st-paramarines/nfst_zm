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
