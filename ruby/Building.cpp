#include <sstream>
#include "Building.hpp"
#include "buildings.hpp"
#include "units.hpp"
#include "Rock.hpp"
#include "UI.hpp"

using namespace std;


bool
Building::upgrade(BuildingType b) {
	Building *building = NULL;

	for (unsigned i = 0; i < buildings_count; i++)
		if ((buildings[i].base == this->type) && (buildings[i].type = b)) {
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

	UI::logAction(this, "upgrade", "upgraded", building);

	delete this;
	return true;
}

static bool
isa(BuildingType is, BuildingType base) {
	while (is != base) {
		if (is == bt_Any)
			return false;

		for (unsigned i = 0; i < buildings_count; i++)
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

	for (unsigned i = 0; i < units_count; i++)
		if ((units[i].type == u) && isa(this->type, units[i].where)) {
			if (this->owner->cost(units[i].gold, units[i].wood))
				unit = units[i].make(this->owner);
			break;
		}

	if (!unit)
		return false;

	pair<int, int> empty = this->map->closestEmpty(this->x, this->y);
	unit->place(this->map, empty.first, empty.second);
	this->owner->addUnit(unit);

	UI::logAction(this, "create", "unit", unit);
	return true;
}

void
Building::damage(int hitpoints) {
	AttackMapItem::damage(hitpoints);

	if (this->hitpoints == 0) {
		UI::logAction(this, "damage", "building dead");
		this->owner->delBuilding(this);

		(new Rock())->place(this->map, this->x, this->y);
		delete this;
	} else {
		ostringstream os;
		os << "lost " << hitpoints << " hp, remaining " << this->hitpoints;
		UI::logAction(this, "damage", os.str());
	}
}

BuildingType
Building::getType() {
	return this->type;
}

string
Building::getPopis() {
	ostringstream os;
	os << "_" << this->owner->getName()[0] << this->owner->getName()[1] << "_";
	os << MapItem::getPopis() << "(" << this->hitpoints << ")";
	return os.str();
}

string
Building::getDetail() {
	ostringstream os;
	os << this->popis << " (hp: " << this->hitpoints << ")";
	return os.str();
}
