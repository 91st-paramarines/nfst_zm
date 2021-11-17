#include "CfgDisplayModuleAirStrikeMacros.hpp"

class GVAR(RscAirStrike): RscDisplayAttributes
{
	onSetFocus = "";
	idc = AIR_STRIKE_IDC_DISPLAY ;
	class controls
	{
		////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT START (by 1st Lt K. Ollo, v1.063, #Givabe)
		////////////////////////////////////////////////////////

		class HeaderBackground: RscText
		{
			idc = AIR_STRIKE_IDC_HEADER_BACKGROUND;
			text = CSTRING(AirStrike_GUI_Title);

			x = 0.29375  * safezoneW + safezoneX;
			y = 0.211917 * safezoneH + safezoneY;
			w = 0.4125   * safezoneW;
			h = 0.033    * safezoneH;

			colorBackground[] = COLOR_HALF_TRANSPARENT_91ST_BLUE;
		};
		class BodyBackground: RscText
		{
			idc = AIR_STRIKE_IDC_BODY_BACKGROUND;

			x = 0.29375 * safezoneW + safezoneX;
			y = 0.247   * safezoneH + safezoneY;
			w = 0.4125  * safezoneW;
			h = 0.484   * safezoneH;

			colorBackground[] = COLOR_HALF_TRANSPARENT_BLACK;
		};
		class CancelButton: RscButtonMenu
		{
			idc = AIR_STRIKE_IDC_CANCEL_BUTTON;
			text = CSTRING(Common_Cancel);
			action = "closeDialog 0";

			x = 0.29375   * safezoneW + safezoneX;
			y = 0.7332    * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.022     * safezoneH;
		};
		class OkButton: RscButtonMenu
		{
			idc = AIR_STRIKE_IDC_OK_BUTTON;
			text = CSTRING(Common_Confirm);
			action = QUOTE( AIR_STRIKE_IDC_INPUTS spawn FUNC(moduleAirStrikeOnConfirm) );

			x = 0.654688  * safezoneW + safezoneX;
			y = 0.7332    * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.022     * safezoneH;
		};
		class PlaneInfoFrame: RscFrame
		{
			idc = AIR_STRIKE_IDC_PLANE_INFO_FRAME;
			text = CSTRING(AirStrike_GUI_Plane);

			x = 0.298906 * safezoneW + safezoneX;
			y = 0.2536   * safezoneH + safezoneY;
			w = 0.195937 * safezoneW;
			h = 0.1364   * safezoneH;
		};
		class PlaneTypeHeader: RscText
		{
			idc     = AIR_STRIKE_IDC_PLANE_TYPE_HEADER;
			text    = CSTRING(AirStrike_GUI_PlaneType);
			tooltip = CSTRING(AirStrike_GUI_PlaneTypeTooltip);

			x = 0.304062  * safezoneW + safezoneX;
			y = 0.269     * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.022     * safezoneH;

			colorBackground[] = COLOR_ONEQUARTER_TRANSPARENT_BLACK;
		};
		class PlaneTypeCombo: RscCombo
		{
			idc = AIR_STRIKE_IDC_PLANE_TYPE_COMBO;

			x = 0.355625 * safezoneW + safezoneX;
			y = 0.269    * safezoneH + safezoneY;
			w = 0.134062 * safezoneW;
			h = 0.022    * safezoneH;

			onLoad         = QUOTE( AIR_STRIKE_IDC_PLANE_TYPE_COMBO spawn FUNC(moduleAirStrikeDisplayPlaneCombo)  );
			onLbSelChanged = QUOTE( AIR_STRIKE_IDC_PLANE_CHANGED    spawn FUNC(moduleAirStrikeDisplayPlaneChanged) );
		};
		class NumberOfPlanesHeader: RscText
		{
			idc     = AIR_STRIKE_IDC_NUMBER_OF_PLANES_HEADER;
			text    = CSTRING(AirStrike_GUI_NumberOfPlanes);
			tooltip = CSTRING(AirStrike_GUI_NumberOfPlanesTooltip);

			x = 0.304062  * safezoneW + safezoneX;
			y = 0.313     * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.022     * safezoneH;

			colorBackground[] = COLOR_ONEQUARTER_TRANSPARENT_BLACK;
		};
		class NumberOfPlanesSlider: RscXSliderH
		{
			idc = AIR_STRIKE_IDC_NUMBER_OF_PLANES_SLIDER;

			x = 0.355615 * safezoneW + safezoneX;
			y = 0.313    * safezoneH + safezoneY;
			w = 0.113437 * safezoneW;
			h = 0.022    * safezoneH;

			sliderRange[]  = AIR_STRIKE_NUMBER_OF_PLANES_RANGE;
			sliderStep     = AIR_STRIKE_NUMBER_OF_PLANES_STEP;
			sliderPosition = AIR_STRIKE_NUMBER_OF_PLANES_DEFAULT;

			onSliderPosChanged = QUOTE( ctrlSetText [AIR_STRIKE_IDC_NUMBER_OF_PLANES_READOUT, str (_this select 1)] );
		};
		class NumberOfPlanesReadout: RscText
		{
			idc  = AIR_STRIKE_IDC_NUMBER_OF_PLANES_READOUT;
			text = AIR_STRIKE_NUMBER_OF_PLANES_DEFAULT;

			x = 0.469062 * safezoneW + safezoneX;
			y = 0.313    * safezoneH + safezoneY;
			w = 0.020625 * safezoneW;
			h = 0.022    * safezoneH;
		};
		class FormationHeader: RscText
		{
			idc     = AIR_STRIKE_IDC_FORMATION_HEADER;
			text    = CSTRING(AirStrike_GUI_Formation);
			tooltip = CSTRING(AirStrike_GUI_FormationTooltip);

			x = 0.304062  * safezoneW + safezoneX;
			y = 0.357     * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.022     * safezoneH;

			colorBackground[] = COLOR_ONEQUARTER_TRANSPARENT_BLACK;
		};
		class FormationCombo: RscCombo
		{
			idc = AIR_STRIKE_IDC_FORMATION_COMBO;

			x = 0.355625 * safezoneW + safezoneX;
			y = 0.357    * safezoneH + safezoneY;
			w = 0.134062 * safezoneW;
			h = 0.022    * safezoneH;

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
		class BombInfoFrame: RscFrame
		{
			idc = AIR_STRIKE_IDC_BOMB_INFO_FRAME;
			text = CSTRING(AirStrike_GUI_Bomb);

			x = 0.505156 * safezoneW + safezoneX;
			y = 0.2536   * safezoneH + safezoneY;
			w = 0.195937 * safezoneW;
			h = 0.1364   * safezoneH;
		};
		class BombTypeHeader: RscText
		{
			idc     = AIR_STRIKE_IDC_BOMB_TYPE_HEADER;
			text    = CSTRING(AirStrike_GUI_BombType);
			tooltip = CSTRING(AirStrike_GUI_BombTypeTooltip);

			x = 0.510312  * safezoneW + safezoneX;
			y = 0.269     * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.022     * safezoneH;

			colorBackground[] = COLOR_ONEQUARTER_TRANSPARENT_BLACK;
		};
		class BombTypeCombo: RscCombo
		{
			idc = AIR_STRIKE_IDC_BOMB_TYPE_COMBO;

			x = 0.561875 * safezoneW + safezoneX;
			y = 0.269    * safezoneH + safezoneY;
			w = 0.134062 * safezoneW;
			h = 0.022    * safezoneH;

			onLbSelChanged = QUOTE( AIR_STRIKE_IDC_BOMB_CHANGED spawn FUNC(moduleAirStrikeDisplayBombChanged) );
		};
		class NumberOfBombsHeader: RscText
		{
			idc     = AIR_STRIKE_IDC_NUMBER_OF_BOMBS_HEADER;
			text    = CSTRING(AirStrike_GUI_NumberOfBombs);
			tooltip = CSTRING(AirStrike_GUI_NumberOfBombsTooltip);

			x = 0.510312  * safezoneW + safezoneX;
			y = 0.313     * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.022     * safezoneH;

			colorBackground[] = COLOR_ONEQUARTER_TRANSPARENT_BLACK;
		};
		class NumberOfBombsSlider: RscXSliderH
		{
			idc = AIR_STRIKE_IDC_NUMBER_OF_BOMBS_SLIDER;

			x = 0.561875 * safezoneW + safezoneX;
			y = 0.313    * safezoneH + safezoneY;
			w = 0.113437 * safezoneW;
			h = 0.022    * safezoneH;

			sliderRange[]  = AIR_STRIKE_NUMBER_OF_BOMBS_RANGE;
			sliderStep     = AIR_STRIKE_NUMBER_OF_BOMBS_STEP;
			sliderPosition = AIR_STRIKE_NUMBER_OF_BOMBS_DEFAULT;

			onSliderPosChanged = QUOTE( ctrlSetText [AIR_STRIKE_IDC_NUMBER_OF_BOMBS_READOUT, str (_this select 1)] );
		};
		class NumberOfBombsReadout: RscText
		{
			idc  = AIR_STRIKE_IDC_NUMBER_OF_BOMBS_READOUT;
			text = AIR_STRIKE_NUMBER_OF_BOMBS_DEFAULT;

			x = 0.675312 * safezoneW + safezoneX;
			y = 0.313    * safezoneH + safezoneY;
			w = 0.020625 * safezoneW;
			h = 0.022    * safezoneH;
		};
		class BombsSpreadHeader: RscText
		{
			idc     = AIR_STRIKE_IDC_BOMBS_SPREAD_HEADER;
			text    = CSTRING(AirStrike_GUI_Dispersion);
			tooltip = CSTRING(AirStrike_GUI_DispersionTooltip);

			x = 0.510312  * safezoneW + safezoneX;
			y = 0.357     * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.022     * safezoneH;

			colorBackground[] = COLOR_ONEQUARTER_TRANSPARENT_BLACK;
		};
		class BombsSpreadSlider: RscXSliderH
		{
			idc = AIR_STRIKE_IDC_BOMBS_SPREAD_SLIDER;

			x = 0.561875 * safezoneW + safezoneX;
			y = 0.357    * safezoneH + safezoneY;
			w = 0.113437 * safezoneW;
			h = 0.022    * safezoneH;

			sliderRange[]  = AIR_STRIKE_BOMBS_SPREAD_RANGE;
			sliderStep     = AIR_STRIKE_BOMBS_SPREAD_STEP;
			sliderPosition = AIR_STRIKE_BOMBS_SPREAD_DEFAULT;

			onSliderPosChanged = QUOTE( ctrlSetText [AIR_STRIKE_IDC_BOMBS_SPREAD_READOUT, str (_this select 1)] );
		};
		class BombsSpreadReadout: RscText
		{
			idc  = AIR_STRIKE_IDC_BOMBS_SPREAD_READOUT   ;
			text = QUOTE(AIR_STRIKE_BOMBS_SPREAD_DEFAULT);

			x = 0.675312 * safezoneW + safezoneX;
			y = 0.357    * safezoneH + safezoneY;
			w = 0.020625 * safezoneW;
			h = 0.022    * safezoneH;
		};
		class FlightInfoFrame: RscFrame
		{
			idc = AIR_STRIKE_IDC_FLIGHT_INFO_FRAME;
			text = CSTRING(AirStrike_GUI_FlightInfo);

			x = 0.298906 * safezoneW + safezoneX;
			y = 0.4076   * safezoneH + safezoneY;
			w = 0.402187 * safezoneW;
			h = 0.0946   * safezoneH;
		};
		class FlightSpeedHeader: RscText
		{
			idc     = AIR_STRIKE_IDC_FLIGHT_SPEED_HEADER;
			text    = CSTRING(AirStrike_GUI_Speed);
			tooltip = CSTRING(AirStrike_GUI_SpeedTooltip);

			x = 0.304062  * safezoneW + safezoneX;
			y = 0.423     * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.022     * safezoneH;

			colorBackground[] = COLOR_ONEQUARTER_TRANSPARENT_BLACK;
		};
		class FlightSpeedSlider: RscXSliderH
		{
			idc = AIR_STRIKE_IDC_FLIGHT_SPEED_SLIDER;

			x = 0.355625 * safezoneW + safezoneX;
			y = 0.423    * safezoneH + safezoneY;
			w = 0.28875  * safezoneW;
			h = 0.022    * safezoneH;

			sliderRange[]  = AIR_STRIKE_FLIGHT_SPEED_RANGE;
			sliderStep     = AIR_STRIKE_FLIGHT_SPEED_STEP;
			sliderPosition = AIR_STRIKE_FLIGHT_SPEED_DEFAULT;

			onSliderPosChanged = QUOTE( AIR_STRIKE_IDC_SPEED_CHANGED spawn FUNC(moduleAirStrikeDisplaySpeedChanged) );
		};
		class FlightSpeedReadout: RscText
		{
			idc = AIR_STRIKE_IDC_FLIGHT_SPEED_READOUT;

			x = 0.644375  * safezoneW + safezoneX;
			y = 0.423     * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.022     * safezoneH;
		};
		class FlightAltitudeHeader: RscText
		{
			idc     = AIR_STRIKE_IDC_FLIGHT_ALTITUDE_HEADER;
			text    = CSTRING(AirStrike_GUI_Altitude);
			tooltip = CSTRING(AirStrike_GUI_AltitudeTooltip);

			x = 0.304062  * safezoneW + safezoneX;
			y = 0.467     * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.022     * safezoneH;

			colorBackground[] = COLOR_ONEQUARTER_TRANSPARENT_BLACK;
		};
		class FlightAltitudeSlider: RscXSliderH
		{
			idc = AIR_STRIKE_IDC_FLIGHT_ALTITUDE_SLIDER;

			x = 0.355625 * safezoneW + safezoneX;
			y = 0.467    * safezoneH + safezoneY;
			w = 0.28875  * safezoneW;
			h = 0.022    * safezoneH;

			sliderRange[]  = AIR_STRIKE_FLIGHT_ALTITUDE_RANGE;
			sliderStep     = AIR_STRIKE_FLIGHT_ALTITUDE_STEP;
			sliderPosition = AIR_STRIKE_FLIGHT_ALTITUDE_DEFAULT;

			onSliderPosChanged = QUOTE( ctrlSetText [AIR_STRIKE_IDC_FLIGHT_ALTITUDE_READOUT, str (_this select 1)] );
		};
		class FlightAltitudeReadout: RscText
		{
			idc  = AIR_STRIKE_IDC_FLIGHT_ALTITUDE_READOUT   ;
			text = QUOTE(AIR_STRIKE_FLIGHT_ALTITUDE_DEFAULT);

			x = 0.644375  * safezoneW + safezoneX;
			y = 0.467     * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.022     * safezoneH;
		};
		class SpawnInfoFrame: RscFrame
		{
			idc = AIR_STRIKE_IDC_SPAWN_INFO_FRAME;
			text = CSTRING(AirStrike_GUI_SpawnInfo);

			x = 0.298906 * safezoneW + safezoneX;
			y = 0.5176   * safezoneH + safezoneY;
			w = 0.402187 * safezoneW;
			h = 0.0946   * safezoneH;
		};
		class SpawnBearingHeader: RscText
		{
			idc     = AIR_STRIKE_IDC_SPAWN_BEARING_HEADER;
			text    = CSTRING(AirStrike_GUI_SpawnBearing);
			tooltip = CSTRING(AirStrike_GUI_SpawnBearingTooltip);

			x = 0.304062  * safezoneW + safezoneX;
			y = 0.533     * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.022     * safezoneH;

			colorBackground[] = COLOR_ONEQUARTER_TRANSPARENT_BLACK;
		};
		class SpawnBearingSlider: RscXSliderH
		{
			idc = AIR_STRIKE_IDC_SPAWN_BEARING_SLIDER;

			x = 0.355625 * safezoneW + safezoneX;
			y = 0.533    * safezoneH + safezoneY;
			w = 0.28875  * safezoneW;
			h = 0.022    * safezoneH;

			sliderRange[]  = AIR_STRIKE_SPAWN_BEARING_RANGE;
			sliderStep     = AIR_STRIKE_SPAWN_BEARING_STEP;
			sliderPosition = AIR_STRIKE_SPAWN_BEARING_DEFAULT;

			onSliderPosChanged = QUOTE( ctrlSetText [AIR_STRIKE_IDC_SPAWN_BEARING_READOUT, str (_this select 1)] );
		};
		class SpawnBearingReadout: RscText
		{
			idc  = AIR_STRIKE_IDC_SPAWN_BEARING_READOUT   ;
			text = QUOTE(AIR_STRIKE_SPAWN_BEARING_DEFAULT);

			x = 0.644375  * safezoneW + safezoneX;
			y = 0.533     * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.022     * safezoneH;
		};
		class SpawnDistanceHeader: RscText
		{
			idc     = AIR_STRIKE_IDC_SPAWN_DISTANCE_HEADER;
			text    = CSTRING(AirStrike_GUI_SpawnDistance);
			tooltip = CSTRING(AirStrike_GUI_SpawnDistanceTooltip);

			x = 0.304062  * safezoneW + safezoneX;
			y = 0.577     * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.022     * safezoneH;

			colorBackground[] = COLOR_ONEQUARTER_TRANSPARENT_BLACK;
		};
		class SpawnDistanceSlider: RscXSliderH
		{
			idc = AIR_STRIKE_IDC_SPAWN_DISTANCE_SLIDER;

			x = 0.355625 * safezoneW + safezoneX;
			y = 0.577    * safezoneH + safezoneY;
			w = 0.28875  * safezoneW;
			h = 0.022    * safezoneH;

			sliderRange[]  = AIR_STRIKE_SPAWN_DISTANCE_RANGE;
			sliderStep     = AIR_STRIKE_SPAWN_DISTANCE_STEP;
			sliderPosition = AIR_STRIKE_SPAWN_DISTANCE_DEFAULT;

			onSliderPosChanged = QUOTE( ctrlSetText [AIR_STRIKE_IDC_SPAWN_DISTANCE_READOUT, str (_this select 1)] );
		};
		class SpawnDistanceReadout: RscText
		{
			idc  = AIR_STRIKE_IDC_SPAWN_DISTANCE_READOUT   ;
			text = QUOTE(AIR_STRIKE_SPAWN_DISTANCE_DEFAULT);

			x = 0.644375  * safezoneW + safezoneX;
			y = 0.577     * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.022     * safezoneH;
		};
		class DespawnInfoFrame: RscFrame
		{
			idc = AIR_STRIKE_IDC_DESPAWN_INFO_FRAME;
			text = CSTRING(AirStrike_GUI_DespawnInfo);

			x = 0.298906 * safezoneW + safezoneX;
			y = 0.6276   * safezoneH + safezoneY;
			w = 0.402187 * safezoneW;
			h = 0.0946   * safezoneH;
		};
		class DespawnBearingHeader: RscText
		{
			idc     = AIR_STRIKE_IDC_DESPAWN_BEARING_HEADER;
			text    = CSTRING(AirStrike_GUI_DespawnBearing);
			tooltip = CSTRING(AirStrike_GUI_DespawnBearingTooltip);

			x = 0.304297  * safezoneW + safezoneX;
			y = 0.643056  * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.022     * safezoneH;

			colorBackground[] = COLOR_ONEQUARTER_TRANSPARENT_BLACK;
		};
		class DespawnBearingSlider: RscXSliderH
		{
			idc = AIR_STRIKE_IDC_DESPAWN_BEARING_SLIDER;

			x = 0.355625 * safezoneW + safezoneX;
			y = 0.643    * safezoneH + safezoneY;
			w = 0.28875  * safezoneW;
			h = 0.022    * safezoneH;

			sliderRange[]  = AIR_STRIKE_DESPAWN_BEARING_RANGE;
			sliderStep     = AIR_STRIKE_DESPAWN_BEARING_STEP;
			sliderPosition = AIR_STRIKE_DESPAWN_BEARING_DEFAULT;

			onSliderPosChanged = QUOTE( ctrlSetText [AIR_STRIKE_IDC_DESPAWN_BEARING_READOUT, str (_this select 1)] );
		};
		class DespawnBearingReadout: RscText
		{
			idc  = AIR_STRIKE_IDC_DESPAWN_BEARING_READOUT   ;
			text = QUOTE(AIR_STRIKE_DESPAWN_BEARING_DEFAULT);

			x = 0.644375  * safezoneW + safezoneX;
			y = 0.643     * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.022     * safezoneH;
		};
		class DespawnDistanceHeader: RscText
		{
			idc     = AIR_STRIKE_IDC_DESPAWN_DISTANCE_HEADER;
			text    = CSTRING(AirStrike_GUI_DespawnDistance);
			tooltip = CSTRING(AirStrike_GUI_DespawnDistanceTooltip);

			x = 0.304062  * safezoneW + safezoneX;
			y = 0.687     * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.022     * safezoneH;

			colorBackground[] = COLOR_ONEQUARTER_TRANSPARENT_BLACK;
		};
		class DespawnDistanceSlider: RscXSliderH
		{
			idc = AIR_STRIKE_IDC_DESPAWN_DISTANCE_SLIDER;

			x = 0.355625 * safezoneW + safezoneX;
			y = 0.687    * safezoneH + safezoneY;
			w = 0.28875  * safezoneW;
			h = 0.022    * safezoneH;

			sliderRange[]  = AIR_STRIKE_DESPAWN_DISTANCE_RANGE;
			sliderStep     = AIR_STRIKE_DESPAWN_DISTANCE_STEP;
			sliderPosition = AIR_STRIKE_DESPAWN_DISTANCE_DEFAULT;

			onSliderPosChanged = QUOTE( ctrlSetText [AIR_STRIKE_IDC_DESPAWN_DISTANCE_READOUT, str (_this select 1)] );
		};
		class DespawnDistanceReadout: RscText
		{
			idc  = AIR_STRIKE_IDC_DESPAWN_DISTANCE_READOUT   ;
			text = QUOTE(AIR_STRIKE_DESPAWN_DISTANCE_DEFAULT);

			x = 0.644375  * safezoneW + safezoneX;
			y = 0.687     * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.022     * safezoneH;
		};
		////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT END
		////////////////////////////////////////////////////////

  };
};
