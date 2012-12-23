#include "units.hpp"
#include "Peon.hpp"
#include "Grunt.hpp"
#include "Axethrower.hpp"

UnitData units[] = {
	{ ut_Peon, Peon::create, "Peon", bt_TownHall },
	{ ut_Grunt, Grunt::create, "Grunt", bt_Barracks },
	{ ut_Axethrower, Axethrower::create, "Axethrower", bt_Barracks },
};

