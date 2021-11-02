// This will be executed once in 3DEN, main menu and before briefing has started for every mission
class Extended_PreInit_EventHandlers
{
	class ADDON
	{
		init = QUOTE( call COMPILE_FILE(XEH_preInit) );
	};
};

// This will be executed once for each mission, once the mission has started
class Extended_PostInit_EventHandlers
{
	class ADDON
	{
		init = QUOTE( call COMPILE_FILE(XEH_postInit) );
	};
};

// This will be executed once before entering the main menu.
class Extended_PreStart_EventHandlers
{
	class ADDON
	{
		init = QUOTE( call COMPILE_FILE(XEH_preStart) );
	};
};
