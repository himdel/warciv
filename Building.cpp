#include <sstream>
#include "Building.hpp"
#include "buildings.hpp"
#include "units.hpp"
using namespace std;


bool
Building::upgrade() {
	Building *building = NULL;

	for (int i = 0; i < buildings_count; i++)
		if (buildings[i].base == this->type) {
			if (this->owner->cost(buildings[i].gold, buildings[i].wood))
				building = buildings[i].make(this->owner);
			break;
		}

	if (!building)
		return false;

	this->remove();
	this->owner->delBuilding(this);

	building->place(this->map, this->x, this->y);
	this->owner->addBuilding(building);

	delete this;
	return true;
}

static bool
isa(BuildingType is, BuildingType base) {
	while (is != base) {
		if (is == bt_Any)
			return false;

		for (int i = 0; i < buildings_count; i++)
			if (is == buildings[i].type) {
				is = buildings[i].base;
				break;
			}
	}
	return true;
}

bool
Building::create(UnitType u) {
	Unit *unit = NULL;

	for (int i = 0; i < units_count; i++)
		if ((units[i].type == u) && isa(this->type, units[i].where)) {
			if (this->owner->cost(units[i].gold, units[i].wood))
				unit = units[i].make(this->owner);
			break;
		}

	if (!unit)
		return false;

	unit->place(this->map, this->x, this->y);
	this->owner->addUnit(unit);
	return true;
}

void
Building::damage(int hitpoints) {
	this->hitpoints -= min(this->hitpoints, hitpoints);
}

string
Building::getPopis() {
	ostringstream os;
	os << MapItem::getPopis() << "(" << this->hitpoints << ")";
	return os.str();
}