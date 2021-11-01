private _pos = uiNamespace getVariable "nfst_moduleFireMissionPos";

private _idcOrdnanceType = _this select 0;
private _idcSplashRadius = _this select 1;
private _idcSafeZone     = _this select 2;
private _idcNbRounds     = _this select 3;
private _idcSalvoLength  = _this select 4;
private _idcNbSalvos     = _this select 5;
private _idcCooldownTime = _this select 6;

private _ordnanceType  = lbData [_idcOrdnanceType, lbCurSel _idcOrdnanceType];
private _splashRadius  = sliderPosition _idcSplashRadius;
private _safeZone      = sliderPosition _idcSafeZone    ;
private _nbRounds      = sliderPosition _idcNbRounds    ;
private _salvoLength   = sliderPosition _idcSalvoLength ;
private _nbSalvos      = sliderPosition _idcNbSalvos    ;
private _cooldownTime  = sliderPosition _idcCooldownTime;

private _delayRounds   = _salvoLength;

if (_nbRounds > 1) then
{
  _delayRounds = _salvoLength / (_nbRounds - 1);
};

closeDialog 0;

for "_i" from 1 to _nbSalvos do
{
  _handle = [_pos, _ordnanceType, _splashRadius, _nbRounds, _delayRounds, {false}, _safeZone] spawn BIS_fnc_fireSupportVirtual;
  waitUntil {scriptDone _handle};
  sleep (_cooldownTime - _delayRounds);
};
