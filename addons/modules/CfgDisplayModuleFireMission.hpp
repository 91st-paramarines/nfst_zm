class RscDisplayAttributesNfstModuleFireMission: RscDisplayAttributes
{
	onSetFocus = "";
	idc = 9100;
	class controls
	{
		////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT START (by 1st Lt K. Ollo, v1.063, #Mawoqi)
		////////////////////////////////////////////////////////

		class BodyBackground: RscText
		{
			idc = 1000;
			x = 0.323801 * safezoneW + safezoneX;
			y = 0.340175 * safezoneH + safezoneY;
			w = 0.352399 * safezoneW;
			h = 0.376059 * safezoneH;
			colorBackground[] = {0,0,0,0.5};
		};
		class ButtonCancel: RscButtonMenu
		{
			idc = 2400;
			text = "Cancel"; //--- ToDo: Localize;
			x = 0.332611 * safezoneW + safezoneX;
			y = 0.641022 * safezoneH + safezoneY;
			w = 0.0704798 * safezoneW;
			h = 0.0564088 * safezoneH;

			action = "closeDialog 0";
		};
		class ButtonOk: RscButtonMenu
		{
			idc = 2401;
			text = "Ok"; //--- ToDo: Localize;
			x = 0.59691 * safezoneW + safezoneX;
			y = 0.641022 * safezoneH + safezoneY;
			w = 0.0704798 * safezoneW;
			h = 0.0564088 * safezoneH;

			action = "execVM '\x\nfst\addons\modules\fnc_moduleFireMissionPostInit.sqf';";
		};
		class DangerZoneRadiusHeader: RscText
		{
			idc = 1001;
			text = "Splash radius"; //--- ToDo: Localize;
			x = 0.332611 * safezoneW + safezoneX;
			y = 0.377781 * safezoneH + safezoneY;
			w = 0.0616698 * safezoneW;
			h = 0.0188029 * safezoneH;
		};
		class SafeZoneRadiusHeader: RscText
		{
			idc = 1002;
			text = "Safe zone"; //--- ToDo: Localize;
			x = 0.332611 * safezoneW + safezoneX;
			y = 0.415387 * safezoneH + safezoneY;
			w = 0.0616698 * safezoneW;
			h = 0.0188029 * safezoneH;
		};
		class OrdnanceHeader: RscText
		{
			idc = 1003;
			text = "Ordnance"; //--- ToDo: Localize;
			x = 0.332611 * safezoneW + safezoneX;
			y = 0.452993 * safezoneH + safezoneY;
			w = 0.0616698 * safezoneW;
			h = 0.0188029 * safezoneH;
		};
		class NumberOfRoundsHeader: RscText
		{
			idc = 1004;
			text = "Rounds per salvo"; //--- ToDo: Localize;
			x = 0.332611 * safezoneW + safezoneX;
			y = 0.490598 * safezoneH + safezoneY;
			w = 0.0616698 * safezoneW;
			h = 0.0188029 * safezoneH;
		};
		class NumberOfSalvosHeader: RscText
		{
			idc = 1005;
			text = "Salvos"; //--- ToDo: Localize;
			x = 0.332611 * safezoneW + safezoneX;
			y = 0.56581 * safezoneH + safezoneY;
			w = 0.0616698 * safezoneW;
			h = 0.0188029 * safezoneH;
		};
		class DelayOfRoundsHeader: RscText
		{
			idc = 1006;
			text = "Rounds delay"; //--- ToDo: Localize;
			x = 0.332611 * safezoneW + safezoneX;
			y = 0.528204 * safezoneH + safezoneY;
			w = 0.0616698 * safezoneW;
			h = 0.0188029 * safezoneH;
		};
		class DelayOfSalvosHeader: RscText
		{
			idc = 1007;
			text = "Salvos delay"; //--- ToDo: Localize;
			x = 0.332611 * safezoneW + safezoneX;
			y = 0.603416 * safezoneH + safezoneY;
			w = 0.0616698 * safezoneW;
			h = 0.0188029 * safezoneH;
		};
		class DangerZoneRadiusSlider: RscXSliderH
		{
			idc = 1900;
			x = 0.40309 * safezoneW + safezoneX;
			y = 0.377781 * safezoneH + safezoneY;
			w = 0.220249 * safezoneW;
			h = 0.0188029 * safezoneH;

			sliderRange[] = {1, 1000};
			sliderStep = 1;

			onSliderPosChanged = "ctrlSetText [1400, str (_this select 1)]";
		};
		class SafeZoneRadiusSlider: RscXSliderH
		{
			idc = 1901;
			x = 0.40309 * safezoneW + safezoneX;
			y = 0.415387 * safezoneH + safezoneY;
			w = 0.220249 * safezoneW;
			h = 0.0188029 * safezoneH;

			sliderRange[] = {0, 1000};
			sliderStep = 1;

			onSliderPosChanged = "ctrlSetText [1401, str (_this select 1)]";
		};
		class NumberOfRoundsSlider: RscXSliderH
		{
			idc = 1903;
			x = 0.40309 * safezoneW + safezoneX;
			y = 0.490598 * safezoneH + safezoneY;
			w = 0.220249 * safezoneW;
			h = 0.0188029 * safezoneH;

			sliderRange[] = {1, 50};
			sliderStep = 1;

			onSliderPosChanged = "ctrlSetText [1403, str (_this select 1)]";
		};
		class DelayOfRoundsSlider: RscXSliderH
		{
			idc = 1904;
			x = 0.40309 * safezoneW + safezoneX;
			y = 0.528204 * safezoneH + safezoneY;
			w = 0.220249 * safezoneW;
			h = 0.0188029 * safezoneH;

			sliderRange[] = {1, 60};
			sliderStep = 1;

			onSliderPosChanged = "ctrlSetText [1404, str (_this select 1)]";
		};
		class NumberOfSalvosSlider: RscXSliderH
		{
			idc = 1905;
			x = 0.40309 * safezoneW + safezoneX;
			y = 0.56581 * safezoneH + safezoneY;
			w = 0.220249 * safezoneW;
			h = 0.0188029 * safezoneH;

			sliderRange[] = {1, 10};
			sliderStep = 1;

			onSliderPosChanged = "ctrlSetText [1405, str (_this select 1)]";
		};
		class DelayOfSalvosSlider: RscXSliderH
		{
			idc = 1906;
			x = 0.40309 * safezoneW + safezoneX;
			y = 0.603416 * safezoneH + safezoneY;
			w = 0.220249 * safezoneW;
			h = 0.0188029 * safezoneH;

			sliderRange[] = {1, 600};
			sliderStep = 1;

			onSliderPosChanged = "ctrlSetText [1406, str (_this select 1)]";
		};
		class DangerZoneRadiusEdit: RscEdit
		{
			idc = 1400;
			x = 0.63215 * safezoneW + safezoneX;
			y = 0.377781 * safezoneH + safezoneY;
			w = 0.0352399 * safezoneW;
			h = 0.0188029 * safezoneH;
		};
		class SafeZoneRadiusEdit: RscEdit
		{
			idc = 1401;
			x = 0.63215 * safezoneW + safezoneX;
			y = 0.415387 * safezoneH + safezoneY;
			w = 0.0352399 * safezoneW;
			h = 0.0188029 * safezoneH;
		};
		class NumberOfRoundsEdit: RscEdit
		{
			idc = 1403;
			x = 0.63215 * safezoneW + safezoneX;
			y = 0.490598 * safezoneH + safezoneY;
			w = 0.0352399 * safezoneW;
			h = 0.0188029 * safezoneH;
		};
		class DelayOfRoundsEdit: RscEdit
		{
			idc = 1404;
			x = 0.63215 * safezoneW + safezoneX;
			y = 0.528204 * safezoneH + safezoneY;
			w = 0.0352399 * safezoneW;
			h = 0.0188029 * safezoneH;
		};
		class NumberOfSalvosEdit: RscEdit
		{
			idc = 1405;
			x = 0.63215 * safezoneW + safezoneX;
			y = 0.56581 * safezoneH + safezoneY;
			w = 0.0352399 * safezoneW;
			h = 0.0188029 * safezoneH;
		};
		class DelayOfSalvosEdit: RscEdit
		{
			idc = 1406;
			x = 0.63215 * safezoneW + safezoneX;
			y = 0.603416 * safezoneH + safezoneY;
			w = 0.0352399 * safezoneW;
			h = 0.0188029 * safezoneH;
		};
		class OrdnanceCombo: RscCombo
		{
			idc = 2100;
			x = 0.40309 * safezoneW + safezoneX;
			y = 0.452993 * safezoneH + safezoneY;
			w = 0.264299 * safezoneW;
			h = 0.0188029 * safezoneH;

			class Items
			{
				class EightTwo
				{
					text = "82mm";
					data = "Sh_82mm_AMOS";
					default = 1;
				};
				class EightTwoSmoke
				{
					text = "82mm (smoke)";
					data = "Smoke_82mm_AMOS_White";
				};
				class OneFiveFive
				{
					text = "155mm";
					data = "Sh_155mm_AMOS ";
				};
			};
		};
		class HeaderBackground: RscText
		{
			idc = 1008;
			x = 0.323801 * safezoneW + safezoneX;
			y = 0.283766 * safezoneH + safezoneY;
			w = 0.352399 * safezoneW;
			h = 0.0564088 * safezoneH;
			colorBackground[] = {0.125,0.286,0.659,0.5};
		};
		class HeaderText: RscText
		{
			idc = 1009;
			text = "Fire Mission"; //--- ToDo: Localize;
			x = 0.332611 * safezoneW + safezoneX;
			y = 0.283766 * safezoneH + safezoneY;
			w = 0.334779 * safezoneW;
			h = 0.0564088 * safezoneH;
			sizeEx = 2 * GUI_GRID_H;
		};
		////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT END
		////////////////////////////////////////////////////////

	};
};
