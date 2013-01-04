#include "Peon.hpp"
#include "Resource.hpp"
#include "enums.hpp"
#include "buildings.hpp"


// we don't unqueue gather, it loops by defualt
bool
Peon::gather(int x, int y) {
	// full, going to townhall
	if (this->cargo) {
		vector< pair<int, int> > path = this->map->closest([] (MapItem *m) {
			// find closest TownHall or descendant
			return dynamic_cast<TownHall *>(m) != NULL;
		}, this->x, this->y);

		if (path.size() < 2)
			this->cargo = false;
		return true;
	}

	bool r = this->move(x, y);
	if (this->distance(x, y) > 1)
		return r;

	// by the spot
	Resource *spot = dynamic_cast<Resource *>( this->map->get(x, y) );
	if (!spot)
		return false;

	this->cargo = !! spot->gather(10, this->owner);
	return this->cargo;
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

	// move unit to closest empty spot
	pair<int, int> empty = this->map->closestEmpty(this->x, this->y);
	this->place(empty.first, empty.second);

	if (this->action == at_Build)
		this->action = at_None;

	return true;
}
