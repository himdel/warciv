#include "WatchTower.hpp"
#include "buildings.hpp"

bool
WatchTower::upgrade() {
	Building *building = NULL;

	for (int i = 0; i < sizeof(buildings) / sizeof(BuildingData); i++)
		if (buildings[i].base == bt_WatchTower) {
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

void
WatchTower::preturnAction() {
//TODO attack
}
