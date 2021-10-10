class RscDisplayAttributesNfstModuleAirStrike: RscDisplayAttributes
{
	onSetFocus = "";
	idc = 9100;
	class controls
	{
		////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT START (by 1st Lt K. Ollo, v1.063, #Pucyne)
		////////////////////////////////////////////////////////

		class HeaderBackground: RscText
		{
			idc = 1001;

			x = 0.324687 * safezoneW + safezoneX;
			y = 0.214 * safezoneH + safezoneY; //0.225
			w = 0.350625 * safezoneW;
			h = 0.055 * safezoneH; //0.044
			colorBackground[] = {0.125,0.286,0.659,0.5}; // TODO: define color as macro
		};
		class HeaderText: RscText
		{
			idc = 1002;

			text = CSTRING(AirStrike_DisplayName);
			x = 0.329844 * safezoneW + safezoneX;
			y = 0.225 * safezoneH + safezoneY;
			w = 0.340312 * safezoneW;
			h = 0.044 * safezoneH;
			sizeEx = 0.05 * safezoneH;
		};
		class BodyBackground: RscText
		{
			idc = 1000;

			x = 0.324687 * safezoneW + safezoneX;
			y = 0.269 * safezoneH + safezoneY;
			w = 0.350625 * safezoneW;
			h = 0.572 * safezoneH;
			colorBackground[] = {0,0,0,0.5};
		};
		class FramePlane: RscFrame
		{
			idc = 1800;

			text = CSTRING(AirStrike_DisplayFramePlane);
			x = 0.335 * safezoneW + safezoneX;
			y = 0.28 * safezoneH + safezoneY;
			w = 0.33 * safezoneW;
			h = 0.11 * safezoneH;
		};
		class HeaderPlaneType: RscText
		{
			idc = 1003;

			text = CSTRING(AirStrike_DisplayHeaderPlaneType);
			x = 0.335 * safezoneW + safezoneX;
			y = 0.291 * safezoneH + safezoneY;
			w = 0.061875 * safezoneW;
			h = 0.022 * safezoneH;
			tooltip = CSTRING(AirStrike_DisplayTooltipPlaneType);
		};
		class ComboPlaneType: RscCombo
		{
			idc = 2100;

			x = 0.407187 * safezoneW + safezoneX;
			y = 0.291 * safezoneH + safezoneY;
			w = 0.252656 * safezoneW;
			h = 0.022 * safezoneH;

			onload = "2100 execVM '\x\nfst\addons\modules\fnc_moduleAirStrikeSetBomberPlanes.sqf';";
			onlbselchanged = "[2102, lbData [2100, lbCurSel 2100]] execVM '\x\nfst\addons\modules\fnc_moduleAirStrikeSetBombs.sqf';";
		};
		class HeaderNumberOfPlanes: RscText
		{
			idc = 1004;

			text = CSTRING(AirStrike_DisplayHeaderPlaneNumber);
			x = 0.335 * safezoneW + safezoneX;
			y = 0.324 * safezoneH + safezoneY;
			w = 0.061875 * safezoneW;
			h = 0.022 * safezoneH;
			tooltip = CSTRING(AirStrike_DisplayTooltipPlaneNumber);
		};
		class SliderNumberOfPlanes: RscXSliderH
		{
			idc = 1900;
			sliderRange[] = {1,9};
			sliderStep = 1;
			sliderPosition = 1;
			onSliderPosChanged = "ctrlSetText [1400, str (_this select 1)]";

			x = 0.407187 * safezoneW + safezoneX;
			y = 0.324 * safezoneH + safezoneY;
			w = 0.226875 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class TextNumberOfPlanes: RscEdit
		{
			idc = 1400;
			canModify = 0;

			text = "1"; //--- ToDo: Localize;
			x = 0.639219 * safezoneW + safezoneX;
			y = 0.324 * safezoneH + safezoneY;
			w = 0.020625 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class HeaderFormation: RscText
		{
			idc = 1005;
			text = CSTRING(AirStrike_DisplayHeaderFormation);
			x = 0.335 * safezoneW + safezoneX;
			y = 0.357 * safezoneH + safezoneY;
			w = 0.061875 * safezoneW;
			h = 0.022 * safezoneH;
			tooltip = CSTRING(AirStrike_DisplayTooltipFormation);
		};
		class ComboFormation: RscCombo
		{
			idc = 2101;

			x = 0.407187 * safezoneW + safezoneX;
			y = 0.357 * safezoneH + safezoneY;
			w = 0.252656 * safezoneW;
			h = 0.022 * safezoneH;

			class Items
			{
				class Wedge
				{
					text = "Wedge"; //TODO
					data = "Wedge";
					default = 1;
				};
				class Column
				{
					text = "Column"; //TODO
					data = "Column";
				};
				class Line
				{
					text = "Line"; //TODO
					data = "Line";
				};
			};
		};
		class FrameOrdnance: RscFrame
		{
			idc = 1801;
			text = CSTRING(AirStrike_DisplayFrameBomb);
			x = 0.335 * safezoneW + safezoneX;
			y = 0.401 * safezoneH + safezoneY;
			w = 0.33 * safezoneW;
			h = 0.11 * safezoneH;
		};
		class HeaderBombType: RscText
		{
			idc = 1006;

			text = CSTRING(AirStrike_DisplayHeaderBombType);
			x = 0.335 * safezoneW + safezoneX;
			y = 0.412 * safezoneH + safezoneY;
			w = 0.061875 * safezoneW;
			h = 0.022 * safezoneH;
			tooltip = CSTRING(AirStrike_DisplayTooltipBombType);
		};
		class ComboBombType: RscCombo
		{
			idc = 2102;

			x = 0.407187 * safezoneW + safezoneX;
			y = 0.412 * safezoneH + safezoneY;
			w = 0.252656 * safezoneW;
			h = 0.022 * safezoneH;

			onLoad = "ctrlEnable [(_this # 0), false];"; // Grey it out as user must first select a bombing plane
		};
		class HeaderBombNumber: RscText
		{
			idc = 1007;

			text = CSTRING(AirStrike_DisplayHeaderBombNumber);
			x = 0.335 * safezoneW + safezoneX;
			y = 0.445 * safezoneH + safezoneY;
			w = 0.061875 * safezoneW;
			h = 0.022 * safezoneH;
			tooltip = CSTRING(AirStrike_DisplayTooltipBombNumber);
		};
		class SliderBombNumber: RscXSliderH
		{
			idc = 1901;
			sliderRange[] = {1,32};
			sliderStep = 1;
			sliderPosition = 4;
			onSliderPosChanged = "ctrlSetText [1401, str (_this select 1)]";

			x = 0.407187 * safezoneW + safezoneX;
			y = 0.445 * safezoneH + safezoneY;
			w = 0.226875 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class TextBombNumber: RscEdit
		{
			idc = 1401;
			canModify = 0;

			text = "4"; //--- ToDo: Localize;
			x = 0.639219 * safezoneW + safezoneX;
			y = 0.445 * safezoneH + safezoneY;
			w = 0.020625 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class HeaderBombDelay: RscText
		{
			idc = 1008;

			text = CSTRING(AirStrike_DisplayHeaderDelay);
			x = 0.335 * safezoneW + safezoneX;
			y = 0.478 * safezoneH + safezoneY;
			w = 0.061875 * safezoneW;
			h = 0.022 * safezoneH;
			tooltip = CSTRING(AirStrike_DisplayTooltipDelay);
		};
		class SliderBombDelay: RscXSliderH
		{
			idc = 1902;
			sliderRange[] = {1,5};
			sliderStep = 1;
			sliderPosition = 1;
			onSliderPosChanged = "ctrlSetText [1402, str (_this select 1)]; ctrlSetText [1403, str round ((_this select 1) * ((sliderPosition 1904)*1000/3600))];";

			x = 0.407187 * safezoneW + safezoneX;
			y = 0.478 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class TextBombDelay: RscEdit
		{
			idc = 1402;
			canModify = 0;

			text = "1"; //--- ToDo: Localize;
			x = 0.489687 * safezoneW + safezoneX;
			y = 0.478 * safezoneH + safezoneY;
			w = 0.0154688 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class HeaderSpread: RscText
		{
			idc = 1009;

			text = CSTRING(AirStrike_DisplayHeaderSpread);
			x = 0.515469 * safezoneW + safezoneX;
			y = 0.478 * safezoneH + safezoneY;
			w = 0.113437 * safezoneW;
			h = 0.022 * safezoneH;
			tooltip = CSTRING(AirStrike_DisplayTooltipSpread);
		};
		class TextSpread: RscEdit
		{
			idc = 1403;
			canModify = 0;

			text = "100"; //--- ToDo: Localize;
			x = 0.639219 * safezoneW + safezoneX;
			y = 0.478 * safezoneH + safezoneY;
			w = 0.020625 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class FrameFlightPlan: RscFrame
		{
			idc = 1802;
			text = CSTRING(AirStrike_DisplayFrameFlightPlan);
			x = 0.335 * safezoneW + safezoneX;
			y = 0.522 * safezoneH + safezoneY;
			w = 0.33 * safezoneW;
			h = 0.209 * safezoneH;
		};
		class HeaderFlightHeight: RscText
		{
			idc = 1010;

			text = CSTRING(AirStrike_DisplayHeaderFlightHeight);
			x = 0.335 * safezoneW + safezoneX;
			y = 0.533 * safezoneH + safezoneY;
			w = 0.061875 * safezoneW;
			h = 0.022 * safezoneH;
			tooltip = CSTRING(AirStrike_DisplayHeaderFlightHeight);
		};
		class SliderFlightHeight: RscXSliderH
		{
			idc = 1903;
			sliderRange[] = {100,1000};
			sliderStep = 1;
			sliderPosition = 150;
			onSliderPosChanged = "ctrlSetText [1404, str (_this select 1)]";

			x = 0.407187 * safezoneW + safezoneX;
			y = 0.533 * safezoneH + safezoneY;
			w = 0.20625 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class TextFlightHeight: RscEdit
		{
			idc = 1404;
			canModify = 0;

			text = "150"; //--- ToDo: Localize;
			x = 0.628906 * safezoneW + safezoneX;
			y = 0.533 * safezoneH + safezoneY;
			w = 0.0309375 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class HeaderFlightSpeed: RscText
		{
			idc = 1011;

			text = CSTRING(AirStrike_DisplayHeaderFlightSpeed);
			x = 0.335 * safezoneW + safezoneX;
			y = 0.566 * safezoneH + safezoneY;
			w = 0.061875 * safezoneW;
			h = 0.022 * safezoneH;
			tooltip = CSTRING(AirStrike_DisplayHeaderFlightSpeed);
		};
		class SliderFlightSpeed: RscXSliderH
		{
			idc = 1904;
			sliderRange[] = {80,500};
			sliderStep = 1;
			sliderPosition = 120;
			onSliderPosChanged = "ctrlSetText [1405, str (_this select 1)]; ctrlSetText [1410, str round ((sliderPosition 1906)/((_this select 1)*1000/3600))]; ctrlSetText [1403, str round ((sliderPosition 1902) * ((_this select 1)*1000/3600))];";

			x = 0.407187 * safezoneW + safezoneX;
			y = 0.566 * safezoneH + safezoneY;
			w = 0.20625 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class TextFlightSpeed: RscEdit
		{
			idc = 1405;
			canModify = 0;

			text = "120"; //--- ToDo: Localize;
			x = 0.628906 * safezoneW + safezoneX;
			y = 0.566 * safezoneH + safezoneY;
			w = 0.0309375 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class HeaderSpawnBearing: RscText
		{
			idc = 1012;

			text = CSTRING(AirStrike_DisplayHeaderSpawnBearing);
			x = 0.335 * safezoneW + safezoneX;
			y = 0.599 * safezoneH + safezoneY;
			w = 0.061875 * safezoneW;
			h = 0.022 * safezoneH;
			tooltip = CSTRING(AirStrike_DisplayTooltipSpawnBearing);
		};
		class SliderSpawnBearing: RscXSliderH
		{
			idc = 1905;
			sliderRange[] = {0,359};
			sliderStep = 1;
			sliderPosition = 180;
			onSliderPosChanged = "ctrlSetText [1406, str (_this select 1)]; ctrlSetText [1411, str (((_this select 1)+180)%360)];";

			x = 0.407187 * safezoneW + safezoneX;
			y = 0.599 * safezoneH + safezoneY;
			w = 0.20625 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class TextSpawnBearing: RscEdit
		{
			idc = 1406;
			canModify = 0;

			text = "180"; //--- ToDo: Localize;
			x = 0.628906 * safezoneW + safezoneX;
			y = 0.599 * safezoneH + safezoneY;
			w = 0.0309375 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class HeaderSpawnDistance: RscText
		{
			idc = 1017;

			text = CSTRING(AirStrike_DisplayHeaderSpawnDistance);
			x = 0.335 * safezoneW + safezoneX;
			y = 0.632 * safezoneH + safezoneY;
			w = 0.061875 * safezoneW;
			h = 0.022 * safezoneH;
			tooltip = CSTRING(AirStrike_DisplayTooltipSpawnDistance);
		};
		class SliderSpawnDistance: RscXSliderH
		{
			idc = 1906;
			sliderRange[] = {1000,10000};
			sliderStep = 1;
			sliderPosition = 500;
			onSliderPosChanged = "ctrlSetText [1407, str (_this select 1)]; ctrlSetText [1410, str round ((_this select 1) / ((sliderPosition 1904)*1000/3600))];";

			x = 0.407187 * safezoneW + safezoneX;
			y = 0.632 * safezoneH + safezoneY;
			w = 0.20625 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class TextSpawnDistance: RscEdit
		{
			idc = 1407;
			canModify = 0;

			text = "1000"; //--- ToDo: Localize;
			x = 0.628906 * safezoneW + safezoneX;
			y = 0.632 * safezoneH + safezoneY;
			w = 0.0309375 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class HeaderDespawnBearing: RscText
		{
			idc = 1013;

			text = CSTRING(AirStrike_DisplayHeaderDespawnBearing);
			x = 0.335 * safezoneW + safezoneX;
			y = 0.665 * safezoneH + safezoneY;
			w = 0.061875 * safezoneW;
			h = 0.022 * safezoneH;
			tooltip = CSTRING(AirStrike_DisplayTooltipDespawnBearing);
		};
		class SliderDespawnBearing: RscXSliderH
		{
			idc = 1907;
			sliderRange[] = {0,359};
			sliderStep = 1;
			sliderPosition = 0;
			onSliderPosChanged = "ctrlSetText [1408, str (_this select 1)]";

			x = 0.407187 * safezoneW + safezoneX;
			y = 0.665 * safezoneH + safezoneY;
			w = 0.20625 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class TextDespawnBearing: RscEdit
		{
			idc = 1408;
			canModify = 0;

			text = "0"; //--- ToDo: Localize;
			x = 0.628906 * safezoneW + safezoneX;
			y = 0.665 * safezoneH + safezoneY;
			w = 0.0309375 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class HeaderDespawnDistance: RscText
		{
			idc = 1014;

			text = CSTRING(AirStrike_DisplayHeaderDespawnDistance);
			x = 0.335 * safezoneW + safezoneX;
			y = 0.698 * safezoneH + safezoneY;
			w = 0.061875 * safezoneW;
			h = 0.022 * safezoneH;
			tooltip = CSTRING(AirStrike_DisplayTooltipDespawnDistance);
		};
		class SliderDespawnDistance: RscXSliderH
		{
			idc = 1908;
			sliderRange[] = {500,10000};
			sliderStep = 1;
			sliderPosition = 1500;
			onSliderPosChanged = "ctrlSetText [1409, str (_this select 1)]";

			x = 0.407187 * safezoneW + safezoneX;
			y = 0.698 * safezoneH + safezoneY;
			w = 0.20625 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class TextDespawnDistance: RscEdit
		{
			idc = 1409;
			canModify = 0;

			text = "1500"; //--- ToDo: Localize;
			x = 0.628906 * safezoneW + safezoneX;
			y = 0.698 * safezoneH + safezoneY;
			w = 0.0309375 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class HeaderETA: RscText
		{
			idc = 1015;

			text = CSTRING(AirStrike_DisplayHeaderETA);
			x = 0.355625 * safezoneW + safezoneX;
			y = 0.753 * safezoneH + safezoneY;
			w = 0.061875 * safezoneW;
			h = 0.022 * safezoneH;
			tooltip = CSTRING(AirStrike_DisplayTooltipETA);
		};
		class TextETA: RscEdit
		{
			idc = 1410;
			canModify = 0;

			text = "1"; //--- ToDo: Localize;
			x = 0.427812 * safezoneW + safezoneX;
			y = 0.753 * safezoneH + safezoneY;
			w = 0.0309375 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class HeaderApproach: RscText
		{
			idc = 1016;

			text = CSTRING(AirStrike_DisplayHeaderApproach);
			x = 0.54125 * safezoneW + safezoneX;
			y = 0.753 * safezoneH + safezoneY;
			w = 0.061875 * safezoneW;
			h = 0.022 * safezoneH;
			tooltip = CSTRING(AirStrike_DisplayTooltipApproach);
		};
		class TextApproach: RscEdit
		{
			idc = 1411;
			canModify = 0;

			text = "0"; //--- ToDo: Localize;
			x = 0.613437 * safezoneW + safezoneX;
			y = 0.753 * safezoneH + safezoneY;
			w = 0.0309375 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class ButtonCancel: RscButtonMenu
		{
			idc = 2400;
			action = "closeDialog 0";

			text = CSTRING(DisplayButtonCancel);
			x = 0.335 * safezoneW + safezoneX;
			y = 0.797 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.022 * safezoneH;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0.8};
		};
		class ButtonOk: RscButtonMenu
		{
			idc = 2401;
			action = "execVM '\x\nfst\addons\modules\fnc_moduleAirStrikePostInit.sqf';";

			text = CSTRING(DisplayButtonOk);
			x = 0.592812 * safezoneW + safezoneX;
			y = 0.797 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.022 * safezoneH;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0.8};
		};
		////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT END
		////////////////////////////////////////////////////////
  };
};
