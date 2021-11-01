#include "script_component.hpp"

class CfgPatches
{
  class ADDON
  {
    // Meta information for editor
    name   = "91st Paramarines - Utility Module";
    author = "Kerpollo";
    url    = "https://www.91st-paramarines.com";

    // Requirements data
    requiredVersion  = 1.98;
    requiredAddons[] = { "CBA_main" };

    // List of added objects and weapons
    units[]   = {};
    weapons[] = {};
  };
};

PRELOAD_ADDONS;
