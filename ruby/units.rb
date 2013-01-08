# not ruby yet!

require './enums.rb'
require './Unit.rb'

struct UnitData {
	UnitType type
	Unit *(*make)(Player *)
	std::string name
	BuildingType where
	int gold
	int wood
end

extern UnitData units[]
extern unsigned units_count

require './units.rb'
require './Peon.rb'
require './Grunt.rb'
require './Axethrower.rb'

UnitData units[] = {
	{ ut_Peon, Peon::create, "Peon", bt_TownHall, 400, 0 },
	{ ut_Grunt, Grunt::create, "Grunt", bt_Barracks, 400, 0 },
	{ ut_Axethrower, Axethrower::create, "Axethrower", bt_Barracks, 500, 50 },
end

unsigned units_count = sizeof(units) / sizeof(UnitData)
