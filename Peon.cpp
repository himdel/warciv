#include "Peon.hpp"
#include "Resource.hpp"
#include "enums.hpp"
#include "buildings.hpp"


bool
Peon::gather(int x, int y) {
	bool r = this->move(x, y);
	if ((this->x != x) && (this->y != y))
		return r;

	// on the spot
	Resource *spot = dynamic_cast<Resource *>( this->map->get(x, y) );
	if (!spot)
		return false;

	return !! spot->gather(10, this->owner);
}

bool
Peon::build(int x, int y, BuildingType b) {
	bool r = this->move(x, y);
	if ((this->x != x) && (this->y != y))
		return r;

	// on the spot
	if (this->map->get(x, y) != NULL)
		return false;

	// actual build
	Building *building = NULL;

	for (unsigned i = 0; i < buildings_count; i++)
		if ((buildings[i].type == b) && (buildings[i].base == bt_Any)) {
			if (this->owner->cost(buildings[i].gold, buildings[i].wood))
				building = buildings[i].make(this->owner);
			break;
		}

	if (!building)
		return false;

	building->place(this->map, this->x, this->y);
	this->owner->addBuilding(building);
	return true;
}
