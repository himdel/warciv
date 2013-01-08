# not ruby yet!

#include <string>
#include "enums.hpp"

struct ActionData {
	ActionType type;
	std::string name;
};

extern ActionData actions[];
extern unsigned actions_count;

#include "actions.hpp"

ActionData actions[] = {
	{ at_None, "(relax)" },
	{ at_Move, "Move" },
	{ at_Attack, "Attack" },
	{ at_Gather, "Gather" },
	{ at_Build, "Build" },
};

unsigned actions_count = sizeof(actions) / sizeof(ActionData);
