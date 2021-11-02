class CfgVehicles
{
	class Logic;
	class Module_F: Logic
	{
		class ModuleDescription;
	};

	class GVAR(zeusModuleBase): Module_F
	{
		scope        = 1;
    scopeCurator = 2;
		vehicleClass = "Modules";
		category     = "NO_CATEGORY";
		function     = "";

		functionPriority   = 1;
		isTriggerActivated = 1;
		is3DEN       = 0;
		isGlobal     = 1;
		isDisposable = 0;
	};

	class GVAR(ModuleArtilleryStrike): GVAR(zeusModuleBase)
	{
		category     = ADDON;
		displayName  = CSTRING(ArtilleryStrike_DisplayName);
		// TODO
		//icon         = "\nfst_modules\data\icon.paa";
		function        = QFUNC(moduleArtilleryStrikeOnPlace);
		curatorInfoType = QGVAR(RscArtilleryStrike);

		class ModuleDescription: ModuleDescription
		{
			description = CSTRING(ArtilleryStrike_Description);
		};
	};

	class GVAR(ModuleAirStrike): GVAR(zeusModuleBase)
	{
		category      = ADDON;
		displayName   = CSTRING(AirStrike_DisplayName);
		// TODO
		//icon         = "\nfst_modules\data\icon.paa";
		function        = QFUNC(moduleAirStrikeOnPlace);
		curatorInfoType = QGVAR(RscAirStrike); //TODO

		class ModuleDescription: ModuleDescription
		{
			description = CSTRING(AirStrike_Description);
		};
	};

};
