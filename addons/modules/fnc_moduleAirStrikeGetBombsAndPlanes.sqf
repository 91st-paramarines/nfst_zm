#include "script_component.hpp"

_bombersInfo = [];

// All vehicles that have pylons (ie only airframes)
_cfgVehicles = "count (_x >> 'Components' >> 'TransportPylonsComponent' >> 'Pylons') > 0" configClasses (configFile >> "CfgVehicles");

for "_i" from 0 to ((count _cfgVehicles)-1) do
{
  _cfgVehicle      = configName (_cfgVehicles select _i);
  _cfgVehicleName  = gettext   (configfile >> "CfgVehicles" >> _cfgVehicle >> "displayName");
  _cfgVehicleScope = getNumber (configfile >> "CfgVehicles" >> _cfgVehicle >> "scope");

  // No base classes (ie only editor version of vehicles)
  if (_cfgVehicleScope == 2) then
  {
    // Gathering all the hardpoints on an airframe, across all of its pylons
    _planeHardpoints = [];
    _pylons = "true" configClasses (configFile >> "Cfgvehicles" >> _cfgVehicle  >> 'Components' >> 'TransportPylonsComponent' >> 'Pylons');
    {
      _pylon = configName (_x);
      _pylonHardpoints = getArray (configfile >> "Cfgvehicles" >> _cfgVehicle >> 'Components' >> 'TransportPylonsComponent' >> 'Pylons' >> _pylon >> 'hardpoints');
      {
        _pylonHardpoint = _pylonHardpoints select _forEachIndex;
        if !(_pylonHardpoint in _planeHardpoints) then
        {
          _planeHardpoints append [_pylonHardpoint];
        };
      } forEach _pylonHardpoints;
    } forEach _pylons;


    _bombsInfo    = [];

    // All hardpoint-mountable magazines
    _cfgMagazines = "isArray (_x >> 'hardpoints')" configClasses (configFile >> "CfgMagazines");
    {
      _cfgMagazine = configName (_x);
      _ammo = getText (configfile >> "CfgMagazines" >> _cfgMagazine >> 'ammo');
      // Magazine ammo is a bomb
      if (["bomb", _ammo] call BIS_fnc_inString) then // TODO : find a more reliable criterion for determining whether an ammo type is a bomb
      {
        scopeName "magazinesLoop";
        _magHardpoints = getArray (configfile >> "CfgMagazines" >> _cfgMagazine >> "hardpoints");
        {
          // Magazine is compatible with the current airframe
          if (_x in _planeHardpoints) then
          {
            _cfgMagazineName       = gettext   (configfile >> "CfgMagazines" >> _cfgMagazine >> "displayName");
            _cfgMagazineAmmoName   = gettext   (configfile >> "CfgMagazines" >> _cfgMagazine >> "ammo");
            _cfgMagazineAmmoCount  = getNumber (configfile >> "CfgMagazines" >> _cfgMagazine >> "count");
            _bombsInfo append [[_cfgMagazine, _cfgMagazineName, _cfgMagazineAmmoName, _cfgMagazineAmmoCount]];
            breakTo "magazinesLoop";
          };
        } forEach _magHardpoints;
      };
    } forEach _cfgMagazines;

    if (count _bombsInfo > 0) then
    {
      _bombersInfo append [[_cfgVehicle, _cfgVehicleName, _bombsInfo]];
    };
  };
};

missionNamespace setVariable ["nfst_moduleAirStrikeBomberPlanes", _bombersInfo];
