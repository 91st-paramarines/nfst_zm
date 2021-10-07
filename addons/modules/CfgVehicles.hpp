class CfgVehicles
{
	class Logic;
	class Module_F: Logic
	{
		class ModuleDescription;
	};


	class NFST_ModuleFireMission: Module_F
	{
		scope        = 1; // 1 : hide, 2 : show
    scopeCurator = 2;
		displayName  = CSTRING(FireMission_DisplayName);
		vehicleClass = "Modules";
		category     = ADDON;
//    icon         = "\nfst_modules\data\icon.paa";

		function         = "nfst_fnc_moduleFireMissionPreInit";
		functionPriority = 1; // Lower number is higher priority
		isGlobal         = 1; // 0 : server only, 1 : global, 2 : persistent global

		isTriggerActivated = 1;
		isDisposable       = 0;
		is3DEN             = 0;

		// Menu displayed when the module is placed or double-clicked on by Zeus
    curatorInfoType = "RscDisplayAttributesNfstModuleFireMission";

		class ModuleDescription: ModuleDescription
		{
			description = CSTRING(FireMission_Description);
		};
	};


	class NFST_ModuleAirStrike: Module_F
	{
		scope        = 1; // 1 : hide, 2 : show
    scopeCurator = 2;
		displayName  = CSTRING(AirStrike_DisplayName); //TODO
		vehicleClass = "Modules";
		category     = ADDON;
//    icon         = "\nfst_modules\data\icon.paa";

		function         = "nfst_fnc_moduleAirStrikePreInit";
		functionPriority = 1; // Lower number is higher priority
		isGlobal         = 1; // 0 : server only, 1 : global, 2 : persistent global

		isTriggerActivated = 1;
		isDisposable       = 0;
		is3DEN             = 0;

		// Menu displayed when the module is placed or double-clicked on by Zeus
    curatorInfoType = "RscDisplayAttributesNfstModuleAirStrike";

		class ModuleDescription: ModuleDescription
		{
			description = CSTRING(AirStrike_Description); //TODO
		};
	};


/*
	class NFST_ModuleSupplyDrop: Module_F
	{
		scope        = 1; // 1 : hide, 2 : show
    scopeCurator = 2;
		displayName  = CSTRING(SupplyDrop_DisplayName);
		vehicleClass = "Modules";
		category     = ADDON;
//    icon         = "\nfst_modules\data\icon.paa";

		function         = "nfst_fnc_moduleSupplyDropPreInit";
		functionPriority = 1; // Lower number is higher priority
		isGlobal         = 1; // 0 : server only, 1 : global, 2 : persistent global

		isTriggerActivated = 1;
		isDisposable       = 0;
		is3DEN             = 0;

		// Menu displayed when the module is placed or double-clicked on by Zeus
    curatorInfoType = "RscDisplayAttributesNfstModuleSupplyDrop";

		class ModuleDescription: ModuleDescription
		{
			description = CSTRING(SupplyDrop_Description);
		};
	};
*/
};
