_cfg = "getnumber( _x >> 'scope' ) isEqualTo 2" configClasses (configFile >> "Cfgvehicles");
for "_i" from 0 to ((count _cfg)-1) do
{
  if (isClass (_cfg select _i)) then
  {
    _cfgNam = configName (_cfg select _i);
		_getSolClas = gettext (configfile >> "Cfgvehicles" >> _cfgNam>> "displayName");
    _getarray = getArray (configfile >> "Cfgvehicles" >> _cfgNam>> "ejectSpeed");
    if (count _getarray > 0) then
    {
      _idx = lbAdd [_this, _getSolClas];
      lbSetData [_this, _idx, _cfgNam];
    };
  };
};
