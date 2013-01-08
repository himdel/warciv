require './enums.rb'
# not ruby yet!

ActionData actions[] = {
	{ at_None, "(relax)" },
	{ at_Move, "Move" },
	{ at_Attack, "Attack" },
	{ at_Gather, "Gather" },
	{ at_Build, "Build" },
end

unsigned actions_count = sizeof(actions) / sizeof(ActionData)
