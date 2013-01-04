#include <sstream>
#include "Unit.hpp"


//TODO no queueing actions yet

//TODO map closest townhall/..
//TODO map closest empty

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
	if (this->distance(x, y) > this->attack_range)
		return this->move(x, y);
	//TODO attack move

	return AttackMapItem::attack(x, y);
}

bool
Unit::stop() {
	// TODO purge queue
	return true;
}

bool
Unit::actionPending() {
	return false;	//TODO
}

bool
Unit::performAction() {
	return false;	//TODO; nevolat kdyz byla rucne akce ten tah
}

std::string
Unit::getPopis() {
	std::ostringstream out;
	out << this->popis << " (" << this->hitpoints << ")";
	return out.str();
}
