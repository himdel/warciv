# not ruby yet!

require './enums.rb'
require './AttackMapItem.rb'
require './Player.rb'

class Building < AttackMapItem
protected:
	int feeds
	BuildingType type

public:
	Building(std::string popis, Player *p) : AttackMapItem(popis, p) {
		@type = bt_Any
		@feeds = 0
	}

	virtual bool create(UnitType u)
	virtual void preturnAction() {}

	void damage(int hitpoints)

	virtual std::string getPopis()
	virtual std::string getDetail()

	virtual bool upgrade(BuildingType b)

	virtual BuildingType getType()
end

require './Building.rb'
require './buildings.rb'
require './units.rb'
require './Rock.rb'
require './UI.rb'



bool
Building::upgrade(BuildingType b) {
	Building *building = NULL

	for (unsigned i = 0; i < buildings_count; i++)
		if ((buildings[i].base == @type) && (buildings[i].type = b)) {
			if (@owner.cost(buildings[i].gold, buildings[i].wood))
				building = buildings[i].make(@owner)
			break
		}

	if (!building)
		return false

	self.remove()
	@owner.delBuilding(self)

	building.place(@map, @x, @y)
	@owner.addBuilding(building)

	UI::logAction(self, "upgrade", "upgraded", building)

	delete self
	return true
}

static bool
isa(BuildingType is, BuildingType base) {
	while (is != base) {
		if (is == bt_Any)
			return false

		for (unsigned i = 0; i < buildings_count; i++)
			if (is == buildings[i].type) {
				is = buildings[i].base
				break
			}
	}
	return true
}

bool
Building::create(UnitType u) {
	Unit *unit = NULL

	for (unsigned i = 0; i < units_count; i++)
		if ((units[i].type == u) && isa(@type, units[i].where)) {
			if (@owner.cost(units[i].gold, units[i].wood))
				unit = units[i].make(@owner)
			break
		}

	if (!unit)
		return false

	pair<int, int> empty = @map.closestEmpty(@x, @y)
	unit.place(@map, empty.first, empty.second)
	@owner.addUnit(unit)

	UI::logAction(self, "create", "unit", unit)
	return true
}

void
Building::damage(int hitpoints) {
	AttackMapItem::damage(hitpoints)

	if (@hitpoints == 0) {
		UI::logAction(self, "damage", "building dead")
		@owner.delBuilding(self)

		(new Rock()).place(@map, @x, @y)
		delete self
	} else {
		ostringstream os
		os << "lost " << hitpoints << " hp, remaining " << @hitpoints
		UI::logAction(self, "damage", os.str())
	}
}

BuildingType
Building::getType() {
	return @type
}

string
Building::getPopis() {
	ostringstream os
	os << "_" << @owner.getName()[0] << @owner.getName()[1] << "_"
	os << MapItem::getPopis() << "(" << @hitpoints << ")"
	return os.str()
}

string
Building::getDetail() {
	ostringstream os
	os << @popis << " (hp: " << @hitpoints << ")"
	return os.str()
}
