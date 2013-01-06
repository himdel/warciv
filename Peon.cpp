#include <sstream>
#include "Peon.hpp"
#include "Resource.hpp"
#include "enums.hpp"
#include "buildings.hpp"
#include "TownHall.hpp"
#include "UI.hpp"


// we don't unqueue gather, it loops by defualt
bool
Peon::gather(int x, int y) {
	// full, going to townhall
	if (this->cargo) {
		// find closest TownHall or descendant
		auto f = [x, y] (MapItem *mi, int px, int py) { return dynamic_cast<TownHall *>(mi) != NULL; };
		list< pair<int, int> > path = this->map->closest(f, this->x, this->y);

		if (path.size() < 2) {
			UI::logAction(this, "gather", "unload cargo", make_pair(x, y));
			this->cargo = false;
			return true;
		}

		return this->move(path.front().first, path.front().second);
	}

	bool r = this->move(x, y);
	if (this->distance(x, y) > 1)
		return r;

	// by the spot
	Resource *spot = dynamic_cast<Resource *>( this->map->get(x, y) );
	if (!spot) {
		UI::logAction(this, "gather", "no resources", make_pair(x, y));
		return false;
	}

	int cargo = spot->gather(10, this->owner);
	this->cargo = !! cargo;

	ostringstream os;
	os << "gathered " << cargo;
	UI::logAction(this, "gather", os.str(), make_pair(x, y), spot);

	return this->cargo;
}

bool
Peon::build(int x, int y, BuildingType b) {
	bool r = this->move(x, y);
	if ((this->x != x) && (this->y != y))
		return r;

	// on the spot
	if (this->map->get(x, y) != NULL) {
		UI::logAction(this, "build", "not empty", make_pair(x, y), this->map->get(x, y));
		return false;
	}

	// actual build
	Building *building = NULL;
	bool found = false;

	for (unsigned i = 0; i < buildings_count; i++)
		if ((buildings[i].type == b) && (buildings[i].base == bt_Any)) {
			if (this->owner->cost(buildings[i].gold, buildings[i].wood))
				building = buildings[i].make(this->owner);
			found = true;
			break;
		}

	if (!found) {
		UI::logAction(this, "build", "can't build that here");
		return false;
	}

	if (!building) {
		UI::logAction(this, "build", "not enough resources");
		return false;
	}

	building->place(this->map, this->x, this->y);
	this->owner->addBuilding(building);

	// move unit to closest empty spot
	pair<int, int> empty = this->map->closestEmpty(this->x, this->y);
	this->place(empty.first, empty.second);

	UI::logAction(this, "build", "built", make_pair(x, y), building);
	UI::logAction(this, "build", "unit moved", empty);

	if (this->pending == at_Build)
		this->pending = at_None;

	return true;
}
