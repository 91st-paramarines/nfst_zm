#include "CfgDisplayModuleArtilleryStrikeMacros.hpp"

class GVAR(RscArtilleryStrike): RscDisplayAttributes
{
	onSetFocus = "";
	idc = ARTY_STRIKE_IDC_DISPLAY;
	class controls
	{
		////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT START (by 1st Lt K. Ollo, v1.063, #Vyhujo)
		////////////////////////////////////////////////////////

		class HeaderBackground: RscText
		{
			idc  = ARTY_STRIKE_IDC_HEADER_BACKGROUND;
			text = CSTRING(ArtilleryStrike_GUI_Title);

			x = 0.29375  * safezoneW + safezoneX;
			y = 0.211917 * safezoneH + safezoneY;
			w = 0.4125   * safezoneW;
			h = 0.033    * safezoneH;

			colorBackground[] = COLOR_HALF_TRANSPARENT_91ST_BLUE;
		};
		class BodyBackground: RscText
		{
			idc = ARTY_STRIKE_IDC_BODY_BACKGROUND;

			x = 0.29375 * safezoneW + safezoneX;
			y = 0.247   * safezoneH + safezoneY;
			w = 0.4125  * safezoneW;
			h = 0.374   * safezoneH;

			colorBackground[] = COLOR_HALF_TRANSPARENT_BLACK;
		};
		class CancelButton: RscButtonMenu
		{
			//idc = 2;
			text = CSTRING(Common_Cancel);
			action = "closeDialog 0";

			x = 0.29375   * safezoneW + safezoneX;
			y = 0.624361  * safezoneH + safezoneY;
			w = 0.0515626 * safezoneW;
			h = 0.0252501 * safezoneH;
		};
		class OkButton: RscButtonMenu
		{
			//idc = 1;
			text = CSTRING(Common_Confirm);
			action = QUOTE( ARTY_STRIKE_IDC_INPUTS spawn FUNC(moduleArtilleryStrikeOnConfirm) );

			x = 0.654687  * safezoneW + safezoneX;
			y = 0.624361  * safezoneH + safezoneY;
			w = 0.0515626 * safezoneW;
			h = 0.0252501 * safezoneH;
		};
		class SplashInfoFrame: RscFrame
		{
			idc  = ARTY_STRIKE_IDC_SPLASH_INFO_FRAME;
			text = CSTRING(ArtilleryStrike_GUI_SplashFrame);


			x = 0.298906 * safezoneW + safezoneX;
			y = 0.2536   * safezoneH + safezoneY;
			w = 0.402187 * safezoneW;
			h = 0.132    * safezoneH;
		};
		class SplashRadiusHeader: RscText
		{
			idc     = ARTY_STRIKE_IDC_SPLASH_RADIUS_HEADER;
			text    = CSTRING(ArtilleryStrike_GUI_Dispersion);
			tooltip = CSTRING(ArtilleryStrike_GUI_DispersionTooltip);

			x = 0.304062 * safezoneW + safezoneX;
			y = 0.269    * safezoneH + safezoneY;
			w = 0.103125 * safezoneW;
			h = 0.022    * safezoneH;

			colorBackground[] = COLOR_ONEQUARTER_TRANSPARENT_BLACK;
		};
		class SplashRadiusSlider: RscXSliderH
		{
			idc = ARTY_STRIKE_IDC_SPLASH_RADIUS_SLIDER;

			x = 0.407187 * safezoneW + safezoneX;
			y = 0.269    * safezoneH + safezoneY;
			w = 0.257813 * safezoneW;
			h = 0.022    * safezoneH;

			sliderRange[]  = {ARTY_STRIKE_MIN_SPLASH_RADIUS, ARTY_STRIKE_MAX_SPLASH_RADIUS};
			sliderStep     = 1;
			sliderPosition = ARTY_STRIKE_DEFAULT_SAFE_ZONE;

			onSliderPosChanged = QUOTE( ARTY_STRIKE_IDC_SPLASH_CHANGED spawn FUNC(moduleArtilleryStrikeDisplaySplashChanged) );
		};
		class SplashRadiusReadout: RscText
		{
			idc  = ARTY_STRIKE_IDC_SPLASH_RADIUS_READOUT;
			text = QUOTE( ARTY_STRIKE_DEFAULT_SPLASH_RADIUS );

			x = 0.665     * safezoneW + safezoneX;
			y = 0.269     * safezoneH + safezoneY;
			w = 0.0309375 * safezoneW;
			h = 0.022     * safezoneH;
		};
		class SafeZoneHeader: RscText
		{
			idc     = ARTY_STRIKE_IDC_SAFE_ZONE_HEADER;
			text    = CSTRING(ArtilleryStrike_GUI_Safezone);
			tooltip = CSTRING(ArtilleryStrike_GUI_SafezoneTooltip);

			x = 0.304062 * safezoneW + safezoneX;
			y = 0.313    * safezoneH + safezoneY;
			w = 0.103125 * safezoneW;
			h = 0.022    * safezoneH;

			colorBackground[] = COLOR_ONEQUARTER_TRANSPARENT_BLACK;
		};
		class SafeZoneSlider: RscXSliderH
		{
			idc = ARTY_STRIKE_IDC_SAFE_ZONE_SLIDER;

			x = 0.407187 * safezoneW + safezoneX;
			y = 0.313    * safezoneH + safezoneY;
			w = 0.257813 * safezoneW;
			h = 0.022    * safezoneH;

			sliderRange[]  = {ARTY_STRIKE_MIN_SAFE_ZONE, ARTY_STRIKE_MAX_SAFE_ZONE};
			sliderStep     = 1;
			sliderPosition = ARTY_STRIKE_DEFAULT_SAFE_ZONE;

			onSliderPosChanged = QUOTE( ctrlSetText [ARTY_STRIKE_IDC_SAFE_ZONE_READOUT, str (_this select 1)] );
		};
		class SafeZoneReadout: RscText
		{
			idc     = ARTY_STRIKE_IDC_SAFE_ZONE_READOUT;
			text    = QUOTE( ARTY_STRIKE_DEFAULT_SAFE_ZONE );

			x = 0.665     * safezoneW + safezoneX;
			y = 0.313     * safezoneH + safezoneY;
			w = 0.0309375 * safezoneW;
			h = 0.022     * safezoneH;
		};
		class OrdnanceTypeHeader: RscText
		{
			idc     = ARTY_STRIKE_IDC_ORDNANCE_TYPE_HEADER;
			text    = CSTRING(ArtilleryStrike_GUI_ShellType);
			tooltip = CSTRING(ArtilleryStrike_GUI_ShellTypeTooltip);

			x = 0.304688 * safezoneW + safezoneX;
			y = 0.358333 * safezoneH + safezoneY;
			w = 0.103125 * safezoneW;
			h = 0.022    * safezoneH;

			colorBackground[] = COLOR_ONEQUARTER_TRANSPARENT_BLACK;
		};
		class OrdnanceTypeCombo: RscCombo
		{
			idc = ARTY_STRIKE_IDC_ORDNANCE_TYPE_COMBO;

			x = 0.407578 * safezoneW + safezoneX;
			y = 0.358506 * safezoneH + safezoneY;
			w = 0.28875  * safezoneW;
			h = 0.022    * safezoneH;

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
		class SalvoInfoFrame: RscFrame
		{
			idc  = ARTY_STRIKE_IDC_SALVO_INFO_FRAME;
			text = CSTRING(ArtilleryStrike_GUI_SalvoFrame);

			x = 0.298906 * safezoneW + safezoneX;
			y = 0.4076   * safezoneH + safezoneY;
			w = 0.402187 * safezoneW;
			h = 0.088    * safezoneH;
		};
		class NumberOfRoundsHeader: RscText
		{
			idc     = ARTY_STRIKE_IDC_NUMBER_OF_ROUNDS_HEADER;
			text    = CSTRING(ArtilleryStrike_GUI_NumberOfRounds);
			tooltip = CSTRING(ArtilleryStrike_GUI_NumberOfRoundsTooltip);

			x = 0.304062 * safezoneW + safezoneX;
			y = 0.423    * safezoneH + safezoneY;
			w = 0.103125 * safezoneW;
			h = 0.022    * safezoneH;

			colorBackground[] = COLOR_ONEQUARTER_TRANSPARENT_BLACK;
		};
		class NumberOfRoundsSlider: RscXSliderH
		{
			idc = ARTY_STRIKE_IDC_NUMBER_OF_ROUNDS_SLIDER;

			x = 0.407187 * safezoneW + safezoneX;
			y = 0.423    * safezoneH + safezoneY;
			w = 0.257813 * safezoneW;
			h = 0.022    * safezoneH;

			sliderRange[]  = {ARTY_STRIKE_MIN_NUMBER_OF_ROUNDS, ARTY_STRIKE_MAX_NUMBER_OF_ROUNDS};
			sliderStep     = 1;
			sliderPosition = ARTY_STRIKE_DEFAULT_NUMBER_OF_ROUNDS;

			onSliderPosChanged = QUOTE( ctrlSetText [ARTY_STRIKE_IDC_NUMBER_OF_ROUNDS_READOUT, str (_this select 1)] );
		};
		class NumberOfRoundsReadout: RscText
		{
			idc = ARTY_STRIKE_IDC_NUMBER_OF_ROUNDS_READOUT;
			text = QUOTE( ARTY_STRIKE_DEFAULT_NUMBER_OF_ROUNDS );

			x = 0.665     * safezoneW + safezoneX;
			y = 0.423     * safezoneH + safezoneY;
			w = 0.0309375 * safezoneW;
			h = 0.022     * safezoneH;
		};
		class SalvoLengthHeader: RscText
		{
			idc     = ARTY_STRIKE_IDC_SALVO_LENGTH_HEADER;
			text    = CSTRING(ArtilleryStrike_GUI_SalvoLength);
			tooltip = CSTRING(ArtilleryStrike_GUI_SalvoLengthTooltip);

			x = 0.304062 * safezoneW + safezoneX;
			y = 0.467    * safezoneH + safezoneY;
			w = 0.103125 * safezoneW;
			h = 0.022    * safezoneH;

			colorBackground[] = COLOR_ONEQUARTER_TRANSPARENT_BLACK;
		};
		class SalvoLengthSlider: RscXSliderH
		{
			idc = ARTY_STRIKE_IDC_SALVO_LENGTH_SLIDER;

			x = 0.407187 * safezoneW + safezoneX;
			y = 0.467    * safezoneH + safezoneY;
			w = 0.257813 * safezoneW;
			h = 0.022    * safezoneH;

			sliderRange[]  = {ARTY_STRIKE_MIN_SALVO_LENGTH, ARTY_STRIKE_MAX_SALVO_LENGTH};
			sliderStep     = 1;
			sliderPosition = ARTY_STRIKE_DEFAULT_SALVO_LENGTH;

			onSliderPosChanged = QUOTE( ctrlSetText [ARTY_STRIKE_IDC_SALVO_LENGTH_READOUT, str (_this select 1)] );
		};
		class SalvoLengthReadout: RscText
		{
			idc  = ARTY_STRIKE_IDC_SALVO_LENGTH_READOUT;
			text = QUOTE( ARTY_STRIKE_DEFAULT_SALVO_LENGTH );

			x = 0.665     * safezoneW + safezoneX;
			y = 0.467     * safezoneH + safezoneY;
			w = 0.0309375 * safezoneW;
			h = 0.022     * safezoneH;
		};
		class FireMissionInfoFrame: RscFrame
		{
			idc  = ARTY_STRIKE_IDC_FIRE_MISSION_INFO_FRAME;
			text = CSTRING(ArtilleryStrike_GUI_MissionFrame);

			x = 0.298906 * safezoneW + safezoneX;
			y = 0.5176   * safezoneH + safezoneY;
			w = 0.402187 * safezoneW;
			h = 0.088    * safezoneH;
		};
		class NumberOfSalvosHeader: RscText
		{
			idc     = ARTY_STRIKE_IDC_NUMBER_OF_SALVOS_HEADER;
			text    = CSTRING(ArtilleryStrike_GUI_NumberOfSalvos);
			tooltip = CSTRING(ArtilleryStrike_GUI_NumberOfSalvosTooltip);

			x = 0.304062 * safezoneW + safezoneX;
			y = 0.533    * safezoneH + safezoneY;
			w = 0.103125 * safezoneW;
			h = 0.022    * safezoneH;

			colorBackground[] = COLOR_ONEQUARTER_TRANSPARENT_BLACK;
		};
		class NumberOfSalvosSlider: RscXSliderH
		{
			idc = ARTY_STRIKE_IDC_NUMBER_OF_SALVOS_SLIDER;

			x = 0.407187 * safezoneW + safezoneX;
			y = 0.533     * safezoneH + safezoneY;
			w = 0.257813 * safezoneW;
			h = 0.022    * safezoneH;

			sliderRange[]  = {ARTY_STRIKE_MIN_NUMBER_OF_SALVOS, ARTY_STRIKE_MAX_NUMBER_OF_SALVOS};
			sliderStep     = 1;
			sliderPosition = ARTY_STRIKE_DEFAULT_NUMBER_OF_SALVOS;

			onSliderPosChanged = QUOTE( ctrlSetText [ARTY_STRIKE_IDC_NUMBER_OF_SALVOS_READOUT, str (_this select 1)] );
		};
		class NumberOfSalvosReadout: RscText
		{
			idc  = ARTY_STRIKE_IDC_NUMBER_OF_SALVOS_READOUT;
			text = QUOTE( ARTY_STRIKE_DEFAULT_NUMBER_OF_SALVOS );

			x = 0.665     * safezoneW + safezoneX;
			y = 0.533     * safezoneH + safezoneY;
			w = 0.0309375 * safezoneW;
			h = 0.022     * safezoneH;
		};
		class CooldownTimeHeader: RscText
		{
			idc     = ARTY_STRIKE_IDC_COOLDOWN_TIME_HEADER;
			text    = CSTRING(ArtilleryStrike_GUI_Cooldown);
			tooltip = CSTRING(ArtilleryStrike_GUI_CooldownTooltip);

			x = 0.304688 * safezoneW + safezoneX;
			y = 0.577778 * safezoneH + safezoneY;
			w = 0.103125 * safezoneW;
			h = 0.022    * safezoneH;

			colorBackground[] = COLOR_ONEQUARTER_TRANSPARENT_BLACK;
		};
		class CooldownTimeSlider: RscXSliderH
		{
			idc = ARTY_STRIKE_IDC_COOLDOWN_TIME_SLIDER;

			x = 0.407187 * safezoneW + safezoneX;
			y = 0.577778 * safezoneH + safezoneY;
			w = 0.257813 * safezoneW;
			h = 0.022    * safezoneH;

			sliderRange[]  = {ARTY_STRIKE_MIN_COOLDOWN_TIME, ARTY_STRIKE_MAX_COOLDOWN_TIME};
			sliderStep     = 1;
			sliderPosition = ARTY_STRIKE_DEFAULT_COOLDOWN_TIME;

			onSliderPosChanged = QUOTE( ctrlSetText [ARTY_STRIKE_IDC_COOLDOWN_TIME_READOUT, str (_this select 1)] );
		};
		class CooldownTimeReadout: RscText
		{
			idc  = ARTY_STRIKE_IDC_COOLDOWN_TIME_READOUT;
			text = QUOTE( ARTY_STRIKE_DEFAULT_COOLDOWN_TIME );

			x = 0.665     * safezoneW + safezoneX;
			y = 0.577778  * safezoneH + safezoneY;
			w = 0.0309375 * safezoneW;
			h = 0.022     * safezoneH;
		};

		////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT END
		////////////////////////////////////////////////////////
	};
};
