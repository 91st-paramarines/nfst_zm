#include "script_component.hpp"

_bombersInfo = [];

_cfgVehicles = "count (_x >> 'Components' >> 'TransportPylonsComponent' >> 'Pylons') > 0" configClasses (configFile >> "CfgVehicles");

for "_i" from 0 to ((count _cfgVehicles)-1) do
{
  _cfgVehicle           = configName (_cfgVehicles select _i);
  _cfgVehicleName       = gettext   (configfile >> "CfgVehicles" >> _cfgVehicle >> "displayName");
  _cfgVehicleScope      = getNumber (configfile >> "CfgVehicles" >> _cfgVehicle >> "scope");
  _cfgVehicleStallSpeed = getNumber (configfile >> "CfgVehicles" >> _cfgVehicle >> "stallSpeed");
  _cfgVehicleMaxSpeed   = getNumber (configfile >> "CfgVehicles" >> _cfgVehicle >> "maxSpeed");

  if (_cfgVehicleScope == 2) then
  {
    _planeCanCarryBombs = false;
    _planeCompatibleMagazines = [];
    _planePylonsMagazinesList = [];

    _pylons = "true" configClasses (configFile >> "Cfgvehicles" >> _cfgVehicle  >> 'Components' >> 'TransportPylonsComponent' >> 'Pylons');
    {
      _pylon = configName (_x);
      _pylonMagazinesList = [];
      _pylonCompatibleMagazines = _cfgVehicle getCompatiblePylonMagazines _pylon;
      {
        _magazineClassName   = _x;
        _magazineDisplayName = getText (configfile >> "CfgMagazines" >> _magazineClassName >> 'displayName');
        _magazineAmmo        = getText (configfile >> "CfgMagazines" >> _magazineClassName >> 'ammo');
        if (["bomb", _magazineAmmo] call BIS_fnc_inString) then
        {
          _planeCanCarryBombs = true;
          if !([_magazineClassName, _magazineDisplayName] in _planeCompatibleMagazines) then
          {
            _planeCompatibleMagazines append [[_magazineClassName, _magazineDisplayName]];
          };
          _magazineAmmoCount =  getNumber (configfile >> "CfgMagazines" >> _magazineClassName >> "count");
          _pylonMagazinesList append [[_magazineClassName, _magazineAmmoCount]];
        };
      } forEach _pylonCompatibleMagazines;

      if ((count _pylonMagazinesList) > 1) then
      {
        _planePylonsMagazinesList append [[_pylon, _pylonMagazinesList]];
      };
    } forEach _pylons;


    if (_planeCanCarryBombs) then
    {
      _bombersInfo append [[_cfgVehicle, _cfgVehicleName, _planeCompatibleMagazines, _planePylonsMagazinesList, _cfgVehicleStallSpeed, _cfgVehicleMaxSpeed]];
    };
  };
};

missionNamespace setVariable ["nfst_moduleAirStrikeBomberPlanes", _bombersInfo];
