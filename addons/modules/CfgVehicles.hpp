class CfgVehicles
{
	class Logic;
	class Module_F: Logic
	{
		class ModuleDescription;
	};

	// TODO CSTRING
	class NFST_ModuleArtilleryStrike: Module_F
	{
		scope        = 1;
    scopeCurator = 2;
		// TODO : Localize
		displayName  = CSTRING(ArtilleryStrike_DisplayName);
		vehicleClass = "Modules";
		category     = ADDON;
		// TODO
//    icon         = "\nfst_modules\data\icon.paa";

		function         = QFUNC(moduleArtilleryStrikeOnPlace);
		functionPriority = 1; // Lower number is higher priority
		isGlobal         = 1; // 0 : server only, 1 : global, 2 : persistent global

		isTriggerActivated = 1;
		isDisposable       = 0;
		is3DEN             = 0;

		// Menu displayed when the module is placed or double-clicked on by Zeus
		// TODO use QGVAR
		curatorInfoType = "RscDisplayAttributesNfstModuleArtilleryStrike";

		class ModuleDescription: ModuleDescription
		{
			description = CSTRING(ArtilleryStrike_Description);
		};
	};
};
