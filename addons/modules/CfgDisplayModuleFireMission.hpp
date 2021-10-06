class RscDisplayAttributesNfstModuleFireMission: RscDisplayAttributes
{
	onSetFocus = "";
	idc = 9100;
	class controls
	{
		////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT START (by 1st Lt K. Ollo, v1.063, #Dozaxe)
		////////////////////////////////////////////////////////

		class HeaderBackground: RscText
		{
			idc = 1008;

			x = 0.324687 * safezoneW + safezoneX;
			y = 0.281409 * safezoneH + safezoneY;
			w = 0.350625 * safezoneW;
			h = 0.055 * safezoneH;
			colorBackground[] = {0.125,0.286,0.659,0.5};
		};
		class HeaderText: RscText
		{
			idc = 1009;

			text = CSTRING(FireMission_DisplayName);
			x = 0.33 * safezoneW + safezoneX;
			y = 0.278909 * safezoneH + safezoneY;
			w = 0.350625 * safezoneW;
			h = 0.055 * safezoneH;
			sizeEx = 0.05 * safezoneH;
		};
		class BodyBackground: RscText
		{
			idc = 1000;

			x = 0.324687 * safezoneW + safezoneX;
			y = 0.335 * safezoneH + safezoneY;
			w = 0.350625 * safezoneW;
			h = 0.374 * safezoneH;
			colorBackground[] = {0,0,0,0.5};
		};
		class ButtonCancel: RscButtonMenu
		{
			idc = 2400;
			action = "closeDialog 0";

			text = CSTRING(DisplayButtonCancel);
			x = 0.335 * safezoneW + safezoneX;
			y = 0.666409 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.022 * safezoneH;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0.8};
		};
		class ButtonOk: RscButtonMenu
		{
			idc = 2401;
			action = "execVM '\x\nfst\addons\modules\fnc_moduleFireMissionPostInit.sqf';";

			text = CSTRING(DisplayButtonOk);
			x = 0.592812 * safezoneW + safezoneX;
			y = 0.665 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.022 * safezoneH;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0.8};
		};
		class DangerZoneRadiusHeader: RscText
		{
			idc = 1001;

			text = CSTRING(FireMission_DisplayHeaderSplashRadius);
			x = 0.335 * safezoneW + safezoneX;
			y = 0.357 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.022 * safezoneH;
			tooltip = CSTRING(FireMission_DisplayTooltipSplashRadius);
		};
		class SafeZoneRadiusHeader: RscText
		{
			idc = 1002;

			text = CSTRING(FireMission_DisplayHeaderSafeZone);
			x = 0.335 * safezoneW + safezoneX;
			y = 0.401 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.022 * safezoneH;
			tooltip = CSTRING(FireMission_DisplayTooltipSafeZone);
		};
		class OrdnanceHeader: RscText
		{
			idc = 1003;

			text = CSTRING(FireMission_DisplayHeaderOrdnanceType);
			x = 0.335 * safezoneW + safezoneX;
			y = 0.445 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.022 * safezoneH;
			tooltip = CSTRING(FireMission_DisplayTooltipOrdnanceType);
		};
		class NumberOfRoundsHeader: RscText
		{
			idc = 1004;

			text = CSTRING(FireMission_DisplayHeaderRoundsPerSalvo);
			x = 0.335 * safezoneW + safezoneX;
			y = 0.489 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.022 * safezoneH;
			tooltip = CSTRING(FireMission_DisplayTooltipRoundsPerSalvo);
		};
		class NumberOfSalvosHeader: RscText
		{
			idc = 1005;

			text = CSTRING(FireMission_DisplayHeaderNumberOfSalvos);
			x = 0.335 * safezoneW + safezoneX;
			y = 0.577 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.022 * safezoneH;
			tooltip = CSTRING(FireMission_DisplayTooltipNumberOfSalvos);
		};
		class DelayOfRoundsHeader: RscText
		{
			idc = 1006;

			text = CSTRING(FireMission_DisplayHeaderDelayOfRounds);
			x = 0.335 * safezoneW + safezoneX;
			y = 0.533 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.022 * safezoneH;
			tooltip = CSTRING(FireMission_DisplayTooltipDelayOfRounds);
		};
		class DelayOfSalvosHeader: RscText
		{
			idc = 1007;

			text = CSTRING(FireMission_DisplayHeaderDelayOfSalvos);
			x = 0.335 * safezoneW + safezoneX;
			y = 0.621 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.022 * safezoneH;
			tooltip = CSTRING(FireMission_DisplayTooltipDelayOfSalvos);
		};
		class DangerZoneRadiusSlider: RscXSliderH
		{
			idc = 1900;
			sliderRange[] = {1,1000};
			sliderStep = 1;
			sliderPosition = 10;
			onSliderPosChanged = "ctrlSetText [1400, str (_this select 1)]";

			x = 0.4175 * safezoneW + safezoneX;
			y = 0.357 * safezoneH + safezoneY;
			w = 0.20625 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class SafeZoneRadiusSlider: RscXSliderH
		{
			idc = 1901;
			sliderRange[] = {0,1000};
			sliderStep = 1;
			sliderPosition = 0;
			onSliderPosChanged = "ctrlSetText [1401, str (_this select 1)]";

			x = 0.4175 * safezoneW + safezoneX;
			y = 0.401 * safezoneH + safezoneY;
			w = 0.20625 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class NumberOfRoundsSlider: RscXSliderH
		{
			idc = 1903;
			sliderRange[] = {1,50};
			sliderStep = 1;
			sliderPosition = 5;
			onSliderPosChanged = "ctrlSetText [1403, str (_this select 1)]";

			x = 0.4175 * safezoneW + safezoneX;
			y = 0.489 * safezoneH + safezoneY;
			w = 0.20625 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class DelayOfRoundsSlider: RscXSliderH
		{
			idc = 1904;
			sliderRange[] = {1,60};
			sliderStep = 1;
			sliderPosition = 2;
			onSliderPosChanged = "ctrlSetText [1404, str (_this select 1)]";

			x = 0.4175 * safezoneW + safezoneX;
			y = 0.533 * safezoneH + safezoneY;
			w = 0.20625 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class NumberOfSalvosSlider: RscXSliderH
		{
			idc = 1905;
			sliderRange[] = {1,10};
			sliderStep = 1;
			sliderPosition = 1;
			onSliderPosChanged = "ctrlSetText [1405, str (_this select 1)]";

			x = 0.4175 * safezoneW + safezoneX;
			y = 0.577 * safezoneH + safezoneY;
			w = 0.20625 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class DelayOfSalvosSlider: RscXSliderH
		{
			idc = 1906;
			sliderRange[] = {1,600};
			sliderStep = 1;
			sliderPosition = 60;
			onSliderPosChanged = "ctrlSetText [1406, str (_this select 1)]";

			x = 0.4175 * safezoneW + safezoneX;
			y = 0.621 * safezoneH + safezoneY;
			w = 0.20625 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class DangerZoneRadiusText: RscEdit
		{
			idc = 1400;
			canModify = 0;

			text = "10"; //--- ToDo: Localize;
			x = 0.633208 * safezoneW + safezoneX;
			y = 0.357 * safezoneH + safezoneY;
			w = 0.0309375 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class SafeZoneRadiusText: RscEdit
		{
			idc = 1401;
			canModify = 0;

			text = "0"; //--- ToDo: Localize;
			x = 0.633208 * safezoneW + safezoneX;
			y = 0.401 * safezoneH + safezoneY;
			w = 0.0309375 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class NumberOfRoundsText: RscEdit
		{
			idc = 1403;
			canModify = 0;

			text = "5"; //--- ToDo: Localize;
			x = 0.634063 * safezoneW + safezoneX;
			y = 0.489 * safezoneH + safezoneY;
			w = 0.0309375 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class DelayOfRoundsText: RscEdit
		{
			idc = 1404;
			canModify = 0;

			text = "2"; //--- ToDo: Localize;
			x = 0.633208 * safezoneW + safezoneX;
			y = 0.533 * safezoneH + safezoneY;
			w = 0.0309375 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class NumberOfSalvosText: RscEdit
		{
			idc = 1405;
			canModify = 0;

			text = "1"; //--- ToDo: Localize;
			x = 0.633208 * safezoneW + safezoneX;
			y = 0.577 * safezoneH + safezoneY;
			w = 0.0309375 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class DelayOfSalvosText: RscEdit
		{
			idc = 1406;
			canModify = 0;

			text = "60"; //--- ToDo: Localize;
			x = 0.633209 * safezoneW + safezoneX;
			y = 0.621 * safezoneH + safezoneY;
			w = 0.0309375 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class OrdnanceCombo: RscCombo
		{
			idc = 2100;

			x = 0.4175 * safezoneW + safezoneX;
			y = 0.445 * safezoneH + safezoneY;
			w = 0.2475 * safezoneW;
			h = 0.022 * safezoneH;

			class Items
		  {
		    class EightTwoSmoke
		    {
		      text = "82mm Smoke Shells";
		      data = "Smoke_82mm_AMOS_White";
		    };
		    class EightTwo
		    {
		      text = "82mm HE Shells";
		      data = "Sh_82mm_AMOS";
		      default = 1;
		    };
		    class OneFiveFive
		    {
		      text = "155mm HE Shells";
		      data = "Sh_155mm_AMOS";
		    };
		  };
		};
		////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT END
		////////////////////////////////////////////////////////
	};
};
