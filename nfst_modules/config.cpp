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
			class Edit;					// Default edit box (i.e., text input field)
			class Combo;				// Default combo box (i.e., drop-down menu)
			class Checkbox;				// Default checkbox (returned value is Boolean)
			class CheckboxNumber;		// Default checkbox (returned value is Number)
			class ModuleDescription;	// Module description
			class Units;				// Selection of units on which the module is applied
		};
		// Description base classes, for more information see below
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

		function         = "nfst_fnc_moduleSupplyDrop"; // Name of function triggered once conditions are met
		functionPriority = 1; // Lower number is higher priority
		isGlobal         = 1; // 0: server only, 1: global, 2: persistent global

        // Obscure attributes
		isTriggerActivated = 1;
		isDisposable       = 1;
		is3DEN             = 0;

		// Menu displayed when the module is placed or double-clicked on by Zeus
        //curatorInfoType = "RscDisplayAttributeModuleNuke";


		// Module attributes, uses https://community.bistudio.com/wiki/Eden_Editor:_Configuring_Attributes#Entity_Specific
		class Attributes: AttributesBase
		{
			class Units: Units
			{
				property = "nfst_ModuleSupplyDrop_Units";
			};
            class FighterEscort
            {
                displayName  = "Fighter Escort?";
                tooltip      = "Is the drop plane escorted by fighter planes?";
                property     = "nfst_ModuleSupplyDrop_FighterEscort";
                unique       = 0;
                validate     = "none";
                condition    = "0";
                typeName     = "BOOL";
                defaultValue = "true";

            };
		};

		// Module description. Must inherit from base class, otherwise pre-defined entities won't be available
		class ModuleDescription: ModuleDescription
		{
			description = "Short module description"; // Short description, will be formatted as structured text
			sync[] = {"LocationArea_F"}; // Array of synced entities (can contain base classes)

			class LocationArea_F
			{
				description[] = { // Multi-line descriptions are supported
					"First line",
					"Second line"
				};
				position = 1; // Position is taken into effect
				direction = 1; // Direction is taken into effect
				optional = 1; // Synced entity is optional
				duplicate = 1; // Multiple entities of this type can be synced
				synced[] = {"BLUFORunit","AnyBrain"}; // Pre-define entities like "AnyBrain" can be used. See the list below
			};
			class BLUFORunit
			{
				description = "Short description";
				displayName = "Any BLUFOR unit"; // Custom name
				icon = "iconMan"; // Custom icon (can be file path or CfgVehicleIcons entry)
				side = 1; // Custom side (will determine icon color)
			};
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
