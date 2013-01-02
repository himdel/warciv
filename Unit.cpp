#include <sstream>
#include "Unit.hpp"
#include "Resource.hpp"


//TODO no queueing actions yet

bool
Unit::move(int x, int y) {
	//TODO proper pathfinding
	//TODO moving too :)
	return false;
}

bool
Unit::gather(int x, int y) {
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
Unit::build(int x, int y, BuildingType b) {
	bool r = this->move(x, y);
	if ((this->x != x) && (this->y != y))
		return r;

	// on the spot
	if (this->map->get(x, y) != NULL)
		return false;

	//TODO build
	return false;
}

bool
Unit::attack(int x, int y) {
	// TODO attackujeme souseda
	// TODO just get within this->attack_distance
	// ..rest done by subclass
	return false;
}

bool
Unit::stop() {
	// TODO purge queue
	return true;
}

void
Unit::die() {
	// TODO remove from map and player units
	this->owner->delUnit(this);
}

bool
Unit::actionPending() {
	return false;	//TODO
}

bool
Unit::performAction() {
	return false;	//TODO
}

std::string
Unit::getPopis() {
	std::ostringstream out;
	out << this->popis << " (" << this->hp << ")";
	return out.str();
}
