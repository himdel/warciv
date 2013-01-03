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
	return false;	// done, overidden in Peon
}

bool
Unit::build(int x, int y, BuildingType b) {
	return false;	// done, overidden in Peon
}

bool
Unit::attack(int x, int y) {
	// TODO attackujeme souseda
	// TODO just get within this->range

	// TODO then check range, damage
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
