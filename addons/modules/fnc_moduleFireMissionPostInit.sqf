private _pos = uiNamespace getVariable "nfst_moduleFireMissionPos";

private _splashRadius = sliderPosition 1900;
private _safeRadius   = sliderPosition 1901;
private _ordnance     = lbData [2100, lbCurSel 2100];
private _nbRounds     = sliderPosition 1903;
private _nbSalvos     = sliderPosition 1905;
private _delayRounds  = sliderPosition 1904;
private _delaySalvos  = sliderPosition 1906;

[_pos, _ordnance, _splashRadius, _nbRounds, _delayRounds, {false}, _safeRadius] spawn BIS_fnc_fireSupportVirtual;

closeDialog 0;
