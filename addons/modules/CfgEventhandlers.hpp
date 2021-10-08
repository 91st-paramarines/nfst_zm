class Extended_PostInit_EventHandlers {
	class ADDON {
		// This will be executed once for each mission, once the mission has started
		init = QUOTE( call COMPILE_FILE(XEH_postInit) );
	};
};
