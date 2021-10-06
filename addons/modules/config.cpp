#include "script_component.hpp"

class CfgPatches
{
	class ADDON
  {
			// Meta information for editor
			name = CSTRING(Component);
			author = "1st Lt K. Ollo";
			url = "https://www.91st-paramarines.com";

			// Requirements data
      requiredVersion = 1.98;
			requiredAddons[] = { "CBA_main" };

			// List of added objects and weapons
			units[] = {"NFST_ModuleFireMission"};
			weapons[] = {};
	};
};

#include "CfgFactionClasses.hpp"
#include "CfgVehicles.hpp"
#include "CfgFunctions.hpp"
#include "CfgDisplayMain.hpp"
