private _pos = uiNamespace getVariable "nfst_moduleFireMissionPos";

params["_idcOrdnanceType", "_idcSplashRadius", "_idcSafeZone", "_idcNbRounds", "_idcSalvoLength", "_idcNbSalvos", "_idcCooldownTime"];

private _ordnanceType  = lbData [_idcOrdnanceType, lbCurSel _idcOrdnanceType];
private _splashRadius  = sliderPosition _idcSplashRadius;
private _safeZone      = sliderPosition _idcSafeZone    ;
private _nbRounds      = sliderPosition _idcNbRounds    ;
private _salvoLength   = sliderPosition _idcSalvoLength ;
private _nbSalvos      = sliderPosition _idcNbSalvos    ;
private _cooldownTime  = sliderPosition _idcCooldownTime;

closeDialog 0;

private _delayRounds   = _salvoLength;
if (_nbRounds > 1) then
{
  _delayRounds = _salvoLength / (_nbRounds - 1);
};


for "_i" from 1 to _nbSalvos do
{
  _handle = [_pos, _ordnanceType, _splashRadius, _nbRounds, _delayRounds, {false}, _safeZone] spawn BIS_fnc_fireSupportVirtual;
  waitUntil {scriptDone _handle};
  sleep (_cooldownTime - _delayRounds);
};
