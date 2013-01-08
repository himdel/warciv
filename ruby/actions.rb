# not ruby yet!

require './enums.rb'

struct ActionData {
	ActionType type;
	std::string name;
end

extern ActionData actions[];
extern unsigned actions_count;

require './actions.rb'

ActionData actions[] = {
	{ at_None, "(relax)" },
	{ at_Move, "Move" },
	{ at_Attack, "Attack" },
	{ at_Gather, "Gather" },
	{ at_Build, "Build" },
end

unsigned actions_count = sizeof(actions) / sizeof(ActionData);
