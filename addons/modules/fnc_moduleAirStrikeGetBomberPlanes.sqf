_bombCarryingPlanes = [];

_cfg = "count (_x >> 'Components' >> 'TransportPylonsComponent' >> 'Pylons') > 0" configClasses (configFile >> "CfgVehicles");

for "_i" from 0 to ((count _cfg)-1) do
{
  scopeName "vehiclesLoop";
  _cfgName = configName (_cfg select _i);
  _cfgDisplayName = gettext (configfile >> "CfgVehicles" >> _cfgName>> "displayName");

  _planeHardpoints = [];

  _pylons = "true" configClasses (configFile >> "Cfgvehicles" >> _cfgName  >> 'Components' >> 'TransportPylonsComponent' >> 'Pylons');
  {
    _pylon = configName (_x);

    _pylonHardpoints = getArray (configfile >> "Cfgvehicles" >> _cfgName >> 'Components' >> 'TransportPylonsComponent' >> 'Pylons' >> _pylon >> 'hardpoints');
    {
      _pylonHardpoint = _pylonHardpoints select _forEachIndex;
      if !(_pylonHardpoint in _planeHardpoints) then
      {
        _planeHardpoints append [_pylonHardpoint];
      };
    } forEach _pylonHardpoints;
  } forEach _pylons;

  _magazines = "isArray (_x >> 'hardpoints')" configClasses (configFile >> "CfgMagazines");
  {
    _magazine = configName (_x);
    _ammo = getText (configfile >> "CfgMagazines" >> _magazine >> 'ammo');
    if (["bomb", _ammo] call BIS_fnc_inString) then
    {
      _magHardpoints = getArray (configfile >> "CfgMagazines" >> _magazine >> 'hardpoints');
      {
        if (_x in _planeHardpoints) then
        {
          _bombCarryingPlanes append [[(count (str _cfgDisplayName)), _cfgName, _cfgDisplayName]];
          breakTo "vehiclesLoop";
        };
      } forEach _magHardpoints;
    };
  } forEach _magazines;
};

missionNamespace setVariable ["nfst_moduleAirStrikeBomberPlanes", _bombCarryingPlanes];
