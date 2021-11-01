class CfgVehicles
{
	class Logic;
	class Module_F: Logic
	{
		class ModuleDescription;
	};


	class NFST_ModuleArtilleryStrike: Module_F
	{
		scope        = 1; // 1 : hide, 2 : show
    scopeCurator = 2;
		displayName  = "91st Paramarines - Artillery Strike";
		vehicleClass = "Modules";
		category     = ADDON;
//    icon         = "\nfst_modules\data\icon.paa";

		function         = QFUNC(moduleArtilleryStrikePreInit);
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
			description = "91st Paramarines - Artillery Strike";
		};
	};
};
