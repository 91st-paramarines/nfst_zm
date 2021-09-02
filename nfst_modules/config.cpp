// Add-on information
class CfgPatches
{
	class nfst_modules
	{
        // Metadata for editor
        name   = "91st Paramarines Custom Modules";
        author = "Kerpollo";
        url    = "https://www.91st-paramarines.com";

        // Requirements data
        requiredVersion  = 1.0;
        requiredAddons[] = {"A3_Modules_F"};

        // List of added content
        units[] = {"nfst_ModuleSupplyDrop"};
        weapons[] = {};
	};
};

//This class defines a custom module category
class CfgFactionClasses
{
	class NO_CATEGORY;
	class nfst_modules: NO_CATEGORY
	{
		displayName = "91st Paramarines";
	};
};


// Getting serious
class CfgVehicles
{
	class Logic;
	class Module_F: Logic
	{
		class AttributesBase
		{
			class Default;
			class Edit;
			class Combo;
			class Checkbox;
			class CheckboxNumber;
			class ModuleDescription;
			class Units;
		};
		class ModuleDescription
		{
			class AnyBrain;
		};
	};
	class nfst_ModuleSupplyDrop: Module_F
	{
		// Standard object definitions
		scope        = 2;              // Editor visibility (1 is hide, 2 is show)
        scopeCurator = 2;              // Zeus visibility
		displayName  = "Supply drop";  // Name displayed in the menu
		category     = "nfst_modules"; // The category we defined above
        icon         = "\nfst_modules\data\icon.paa"; // Delete to use the default icon

		//function         = "nfst_fnc_moduleSupplyDrop"; // Name of function triggered once conditions are met
		functionPriority = 1; // Lower number is higher priority
		isGlobal         = 0; // 0: server only, 1: global, 2: persistent global

        // Obscure attributes
		isTriggerActivated = 1;
		isDisposable       = 0;
		is3DEN             = 0;

		// Menu displayed when the module is placed or double-clicked on by Zeus
        curatorInfoType = "RscDisplayAttributesNfstModules";


		// Module attributes, uses https://community.bistudio.com/wiki/Eden_Editor:_Configuring_Attributes#Entity_Specific
		class Attributes: AttributesBase
		{
			class Units: Units
			{
				property = "nfst_ModuleSupplyDrop_Units";
			};
            class FighterEscort: Checkbox
            {
                displayName  = "Fighter Escort?";
                tooltip      = "Is the drop plane escorted by fighter planes?";
                property     = "nfst_ModuleSupplyDrop_FighterEscort";
                unique       = 0;
                validate     = "none";
                condition    = "0";
                typeName     = "BOOL";
                defaultValue = "false";

            };
		};

		class ModuleDescription: ModuleDescription
		{
			description = "IT'S CALLED SUPPLY DROP, WHAT DO YOU THINK IT DOES?";
		};
	};
};

// Declaring all functions used by the module
class CfgFunctions
{
	class nfst
	{
		class All
		{
            class moduleSupplyDrop
            {
                file = "nfst_modules\functions\fn_moduleSupplyDrop.sqf";
            };
		};
	};
};


class RscDisplayAttributes;
class RscFrame;
class RscPicture;
class RscButton;

class RscDisplayAttributesNfstModules: RscDisplayAttributes
{
    movingEnable = true;
    enableSimulation = true;
    class controls {
        ////////////////////////////////////////////////////////
        // GUI EDITOR OUTPUT START (by 1st Lt K. Ollo, v1.063, #Zybedo)
        ////////////////////////////////////////////////////////

        class RscFrame_1800: RscFrame
        {
        	idc = 1800;
        	x = 0.0760149;
        	y = 0.234848;
        	w = 0.1;
        	h = 0.1;
        };
        class nfst_RscPicture: RscPicture
        {
        	idc = 1200;
        	text = "#(argb,8,8,3)color(1,1,1,1)";
        	x = 0.293584 * safezoneW + safezoneX;
        	y = 0.225 * safezoneH + safezoneY;
        	w = 0.412833 * safezoneW;
        	h = 0.55 * safezoneH;
        	colorBackground[] = {0,0,0,1};
        	colorActive[] = {0,0,0,1};
        };
        class nfst_RscButtonOk: RscButton
        {
        	idc = 1600;
        	text = "Ok"; //--- ToDo: Localize;
        	x = 0.654812 * safezoneW + safezoneX;
        	y = 0.698 * safezoneH + safezoneY;
        	w = 0.0412833 * safezoneW;
        	h = 0.055 * safezoneH;
            action = "execVM 'nfst_modules\functions\fn_moduleSupplyDrop.sqf'";
        };
        class nsft_RscButtonCancel: RscButton
        {
        	idc = 1601;
        	text = "Cancel"; //--- ToDo: Localize;
        	x = 0.303904 * safezoneW + safezoneX;
        	y = 0.698 * safezoneH + safezoneY;
        	w = 0.0412833 * safezoneW;
        	h = 0.055 * safezoneH;
            action = "closeDialog 0";
        };

        ////////////////////////////////////////////////////////
        // GUI EDITOR OUTPUT END
        ////////////////////////////////////////////////////////
    };
};
