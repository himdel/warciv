# not ruby yet!

#include "enums.hpp"
#include "Unit.hpp"

struct UnitData {
	UnitType type;
	Unit *(*make)(Player *);
	std::string name;
	BuildingType where;
	int gold;
	int wood;
};

extern UnitData units[];
extern unsigned units_count;

#include "units.hpp"
#include "Peon.hpp"
#include "Grunt.hpp"
#include "Axethrower.hpp"

UnitData units[] = {
	{ ut_Peon, Peon::create, "Peon", bt_TownHall, 400, 0 },
	{ ut_Grunt, Grunt::create, "Grunt", bt_Barracks, 400, 0 },
	{ ut_Axethrower, Axethrower::create, "Axethrower", bt_Barracks, 500, 50 },
};

unsigned units_count = sizeof(units) / sizeof(UnitData);
