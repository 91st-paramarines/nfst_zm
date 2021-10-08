params ["_planesCombo"];

private _bombCarryingPlanes = missionNamespace getVariable "nfst_moduleAirStrikeBomberPlanes";

_cfg = "true" configClasses (configFile >> "Cfgvehicles");
for "_i" from 0 to ((count _cfg)-1) do
{
  if (isClass (_cfg select _i)) then
  {
    _cfgNam = configName (_cfg select _i);
    _getSolClas = gettext (configfile >> "Cfgvehicles" >> _cfgNam>> "displayName");
    _getarray = getArray (configfile >> "Cfgvehicles" >> _cfgNam>> "ejectSpeed");
    _getweapons = getArray (configfile >> "Cfgvehicles" >> _cfgNam>> "weapons");

    if ((count _getarray > 0) and (count _getweapons > 0)) then
    {
      _hasBombs = false;
      {
        if (["bomb", _x] call BIS_fnc_inString) then {_hasBombs = true;};
      } forEach _getweapons;
      if (_hasBombs) then
      {
        _idx = lbAdd [_this, _getSolClas];
        lbSetData [_this, _idx, _cfgNam];
      };
    };
  };
};
