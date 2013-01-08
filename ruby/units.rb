require './Axethrower.rb'
require './Grunt.rb'
require './Peon.rb'
require './Unit.rb'
require './enums.rb'
# not ruby yet!


struct UnitData {
	UnitType type
	Unit (make)(Player )
	string name
	BuildingType where
	int gold
	int wood
end



UnitData units[] = {
	{ ut_Peon, Peon::create, "Peon", bt_TownHall, 400, 0 },
	{ ut_Grunt, Grunt::create, "Grunt", bt_Barracks, 400, 0 },
	{ ut_Axethrower, Axethrower::create, "Axethrower", bt_Barracks, 500, 50 },
end

unsigned units_count = sizeof(units) / sizeof(UnitData)
