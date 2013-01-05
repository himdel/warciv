#include "actions.hpp"

ActionData actions[] = {
	{ at_None, "(relax)" },
	{ at_Move, "Move" },
	{ at_Attack, "Attack" },
	{ at_Gather, "Gather" },
	{ at_Build, "Build" },
};

unsigned actions_count = sizeof(actions) / sizeof(ActionData);
