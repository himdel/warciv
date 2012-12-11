#include "units.hpp"
#include "Peon.hpp"
#include "Grunt.hpp"
#include "Axethrower.hpp"

UnitData units[] = {
	{ ut_Peon, Peon::create, "Peon", TownHall },
	{ ut_Grunt, Grunt::create, "Grunt", Barracks },
	{ ut_Axethrower, Axethrower::create, "Axethrower", Barracks },
};
