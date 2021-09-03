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
        curatorInfoType = "RscDisplayAttributesNfstModuleSupplyDrop";


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
class IGUIBack;
class RscButton;
class RscButtonMenu;
class RscButtonMenuCancel;
class RscButtonMenuOK;
class RscCheckbox;
class RscCombo;
class RscControlsGroup;
class RscListBox;
class RscSlider;
class RscText;
class RscEdit;
class RscXSliderH;

class RscDisplayAttributesNfstModuleSupplyDrop: RscDisplayAttributes
{
	onSetFocus = "";
	idc = -1;
	class controls
	{
        ////////////////////////////////////////////////////////
        // GUI EDITOR OUTPUT START (by 1st Lt K. Ollo, v1.063, #Geniwi)
        ////////////////////////////////////////////////////////
        // Header
        class RscText_Header_Background: RscText
        {
            idc = 1000;

            x = 0.293584 * safezoneW + safezoneX;
            y = 0.225 * safezoneH + safezoneY;
            w = 0.412833 * safezoneW;
            h = 0.055 * safezoneH;
            colorBackground[] = {0.125,0.286,0.659,0.5};
        };
        class RscText_HeaderText: RscText
        {
            idc = 1001;

            text = "Supply drop"; //--- ToDo: Localize;
            x = 0.293584 * safezoneW + safezoneX;
            y = 0.225 * safezoneH + safezoneY;
            w = 0.412833 * safezoneW;
            h = 0.055 * safezoneH;
        };
        // Body
        class RscText_BodyBackground: RscText
        {
        	idc = 1002;

        	x = 0.293584 * safezoneW + safezoneX;
        	y = 0.28 * safezoneH + safezoneY;
        	w = 0.412833 * safezoneW;
        	h = 0.495 * safezoneH;
        	colorBackground[] = {0,0,0,0.5};
        };
        class RscButtonMenu_Ok: RscButtonMenu
        {
            idc = 2400;

            text = "Ok"; //--- ToDo: Localize;
            x = 0.520642 * safezoneW + safezoneX;
            y = 0.291 * safezoneH + safezoneY;
            w = 0.180614 * safezoneW;
            h = 0.044 * safezoneH;
            colorText[] = {1,1,1,1};
            colorBackground[] = {0,0,0,0.8};
        };
        class RscButtonMenu_Cancel: RscButtonMenu
        {
            idc = 2401;

            text = "Cancel"; //--- ToDo: Localize;
            x = 0.298744 * safezoneW + safezoneX;
            y = 0.291 * safezoneH + safezoneY;
            w = 0.175454 * safezoneW;
            h = 0.044 * safezoneH;
            colorText[] = {1,1,1,1};
            colorBackground[] = {0,0,0,0.8};

            action = "closeDialog 0";
        };
        // Spawn parameters
        class RscFrame_Spawn: RscFrame
        {
        	idc = 1800;

        	x = 0.298744 * safezoneW + safezoneX;
        	y = 0.346 * safezoneH + safezoneY;
        	w = 0.402512 * safezoneW;
        	h = 0.088 * safezoneH;
        };
        class RscText_SpawnDistance: RscText
        {
            idc = 1003;

            text = "Spawn point distance"; //--- ToDo: Localize;
            x = 0.303904 * safezoneW + safezoneX;
            y = 0.357 * safezoneH + safezoneY;
            w = 0.087727 * safezoneW;
            h = 0.022 * safezoneH;
            tooltip = "Distance from the plane's spawn point to the drop point"; //--- ToDo: Localize;
        };
        class RscSlider_SpawnDistance: RscXSliderH
        {
            idc = 1900;

            x = 0.407113 * safezoneW + safezoneX;
            y = 0.357 * safezoneH + safezoneY;
            w = 0.216737 * safezoneW;
            h = 0.022 * safezoneH;

            onSliderPosChanged = "ctrlSetText [1400, str (_this select 1)]";
        };
        class RscEdit_SpawnDistance: RscEdit
        {
            idc = 1400;

            x = 0.634171 * safezoneW + safezoneX;
            y = 0.357 * safezoneH + safezoneY;
            w = 0.0516041 * safezoneW;
            h = 0.022 * safezoneH;
        };
        class RscText_SpawnBearing: RscText
        {
            idc = 1004;

            text = "Spawn point bearing"; //--- ToDo: Localize;
            x = 0.303904 * safezoneW + safezoneX;
            y = 0.401 * safezoneH + safezoneY;
            w = 0.087727 * safezoneW;
            h = 0.022 * safezoneH;
            tooltip = "Bearing to the plane's spawn point, relative to the drop point"; //--- ToDo: Localize;
        };
        class RscSlider_SpawnBearing: RscXSliderH
        {
            idc = 1901;

            x = 0.407113 * safezoneW + safezoneX;
            y = 0.401 * safezoneH + safezoneY;
            w = 0.216737 * safezoneW;
            h = 0.022 * safezoneH;

            onSliderPosChanged = "ctrlSetText [1401, str (_this select 1)]";
        };
        class RscEdit_SpawnBearing: RscEdit
        {
            idc = 1401;

            x = 0.634171 * safezoneW + safezoneX;
            y = 0.401 * safezoneH + safezoneY;
            w = 0.0516041 * safezoneW;
            h = 0.022 * safezoneH;
        };
        // Despawn settings
        class RscFrame_Despawn: RscFrame
        {
        	idc = 1801;

        	x = 0.298744 * safezoneW + safezoneX;
        	y = 0.456 * safezoneH + safezoneY;
        	w = 0.402512 * safezoneW;
        	h = 0.088 * safezoneH;
        };
        class RscText_DespawnDistance: RscText
        {
            idc = 1005;

            text = "Despawn point distance"; //--- ToDo: Localize;
            x = 0.303904 * safezoneW + safezoneX;
            y = 0.467 * safezoneH + safezoneY;
            w = 0.0928874 * safezoneW;
            h = 0.022 * safezoneH;
            tooltip = "Distance from the plane's despawn point to the drop point"; //--- ToDo: Localize;
        };
        class RscSlider_DespawnDistance: RscXSliderH
        {
            idc = 1902;

            x = 0.407113 * safezoneW + safezoneX;
            y = 0.467 * safezoneH + safezoneY;
            w = 0.216737 * safezoneW;
            h = 0.022 * safezoneH;

            onSliderPosChanged = "ctrlSetText [1402, str (_this select 1)]";
        };
        class RscEdit_DespawnDistance: RscEdit
        {
            idc = 1402;

            x = 0.634171 * safezoneW + safezoneX;
            y = 0.467 * safezoneH + safezoneY;
            w = 0.0516041 * safezoneW;
            h = 0.022 * safezoneH;
        };
        class RscText_DespawnBearing: RscText
        {
            idc = 1006;

            text = "Despawn point bearing"; //--- ToDo: Localize;
            x = 0.303904 * safezoneW + safezoneX;
            y = 0.511 * safezoneH + safezoneY;
            w = 0.087727 * safezoneW;
            h = 0.022 * safezoneH;
            tooltip = "Bearing to the plane's despawn point, relative to the drop point"; //--- ToDo: Localize;
        };
        class RscSlider_DespawnBearing: RscXSliderH
        {
            idc = 1903;

            x = 0.407113 * safezoneW + safezoneX;
            y = 0.511 * safezoneH + safezoneY;
            w = 0.216737 * safezoneW;
            h = 0.022 * safezoneH;

            onSliderPosChanged = "ctrlSetText [1403, str (_this select 1)]";
        };
        class RscEdit_DespawnBearing: RscEdit
        {
            idc = 1403;

            x = 0.634171 * safezoneW + safezoneX;
            y = 0.511 * safezoneH + safezoneY;
            w = 0.0516041 * safezoneW;
            h = 0.022 * safezoneH;
        };
        // Flight settings
        class RscFrame_Flight: RscFrame
        {
        	idc = 1802;

        	x = 0.298744 * safezoneW + safezoneX;
        	y = 0.566 * safezoneH + safezoneY;
        	w = 0.402512 * safezoneW;
        	h = 0.088 * safezoneH;
        };
        class RscText_FlightSpeed: RscText
        {
            idc = 1007;

            text = "Flight speed"; //--- ToDo: Localize;
            x = 0.303904 * safezoneW + safezoneX;
            y = 0.577 * safezoneH + safezoneY;
            w = 0.087727 * safezoneW;
            h = 0.022 * safezoneH;
            tooltip = "The plane's flight and drop speed"; //--- ToDo: Localize;
        };
        class RscSlider_FlightSpeed: RscXSliderH
        {
            idc = 1904;

            x = 0.407113 * safezoneW + safezoneX;
            y = 0.577 * safezoneH + safezoneY;
            w = 0.216737 * safezoneW;
            h = 0.022 * safezoneH;

            onSliderPosChanged = "ctrlSetText [1404, str (_this select 1)]";
        };
        class RscEdit_FlightSpeed: RscEdit
        {
            idc = 1404;

            x = 0.634171 * safezoneW + safezoneX;
            y = 0.577 * safezoneH + safezoneY;
            w = 0.0516041 * safezoneW;
            h = 0.022 * safezoneH;
        };
        class RscText_FlightAltitude: RscText
        {
            idc = 1008;

            text = "Flight altitude"; //--- ToDo: Localize;
            x = 0.303904 * safezoneW + safezoneX;
            y = 0.621 * safezoneH + safezoneY;
            w = 0.087727 * safezoneW;
            h = 0.022 * safezoneH;
            tooltip = "The plane's flight and drop altitude"; //--- ToDo: Localize;
        };
        class RscSlider_FlightAltitude: RscXSliderH
        {
            idc = 1905;

            x = 0.407113 * safezoneW + safezoneX;
            y = 0.621 * safezoneH + safezoneY;
            w = 0.216737 * safezoneW;
            h = 0.022 * safezoneH;

            onSliderPosChanged = "ctrlSetText [1405, str (_this select 1)]";
        };
        class RscEdit_FlightAltitude: RscEdit
        {
            idc = 1405;

            x = 0.634171 * safezoneW + safezoneX;
            y = 0.621 * safezoneH + safezoneY;
            w = 0.0516041 * safezoneW;
            h = 0.022 * safezoneH;
        };
        //Escort settings
        class RscFrame_Escort: RscFrame
        {
        	idc = 1803;

        	x = 0.298744 * safezoneW + safezoneX;
        	y = 0.676 * safezoneH + safezoneY;
        	w = 0.402512 * safezoneW;
        	h = 0.088 * safezoneH;
        };
        class RscText_FighterEscort: RscText
        {
            idc = 1009;

            text = "Fighter escort"; //--- ToDo: Localize;
            x = 0.303904 * safezoneW + safezoneX;
            y = 0.687 * safezoneH + safezoneY;
            w = 0.087727 * safezoneW;
            h = 0.022 * safezoneH;
            tooltip = "Does the drop plane have a fighter escort?"; //--- ToDo: Localize;
        };
        class RscCheckbox_FighterEscort: RscCheckBox
        {
            idc = 2800;
            onCheckedChanged = "nfst_moduleSupplyDrop_hasEscort = (_this select 1)";

            x = 0.50516 * safezoneW + safezoneX;
            y = 0.687 * safezoneH + safezoneY;
            w = 0.012665 * safezoneW;
            h = 0.022 * safezoneH;
        };
        class RscText_EscortSize: RscText
        {
            idc = 1010;

            text = "Escort size"; //--- ToDo: Localize;
            x = 0.303904 * safezoneW + safezoneX;
            y = 0.731 * safezoneH + safezoneY;
            w = 0.0865548 * safezoneW;
            h = 0.0213055 * safezoneH;
            tooltip = "Flying in a tactical blob around the drop plane"; //--- ToDo: Localize;
        };
        class RscSlider_EscortSize: RscXSliderH
        {
            idc = 1906;

            x = 0.407113 * safezoneW + safezoneX;
            y = 0.731 * safezoneH + safezoneY;
            w = 0.216737 * safezoneW;
            h = 0.022 * safezoneH;

            onSliderPosChanged = "ctrlSetText [1406, str (_this select 1)]";
        };
        class RscEdit_EscortSize: RscEdit
        {
            idc = 1406;

            x = 0.634171 * safezoneW + safezoneX;
            y = 0.731 * safezoneH + safezoneY;
            w = 0.0516041 * safezoneW;
            h = 0.022 * safezoneH;
        };
        ////////////////////////////////////////////////////////
        // GUI EDITOR OUTPUT END
        ////////////////////////////////////////////////////////

	};
};
