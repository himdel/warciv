#include <sstream>
#include "Unit.hpp"


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

void
Unit::damage(int hitpoints) {
	AttackMapItem::damage(hitpoints);

	if (this->hitpoints == 0) {
		this->owner->delUnit(this);
		delete this;
	}
}

bool
Unit::attack(int x, int y) {
	// TODO attackujeme souseda
	// TODO just get within this->range

	return AttackMapItem::attack(x, y);
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
	out << this->popis << " (" << this->hitpoints << ")";
	return out.str();
}
