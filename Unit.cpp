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
	// if not in range, attack anything or move
	if (this->distance(x, y) > this->attack_range) {
		if (this->attack())
			return true;
		return this->move(x, y);
	}

	return AttackMapItem::attack(x, y);
}

void
Unit::stop() {
	this->pending = at_None;
	this->pending_build = bt_Any;
	this->pending_x = this->x;
	this->pending_y = this->y;
}

bool
Unit::actionPending() {
	return this->pending != at_None;
}

// nevolat pokud byl tah delan rucne
bool
Unit::performAction() {
	if (!this->actionPending())
		return false;

	if (this->pending == at_Move)
		return this->move(this->pending_x, this->pending_y);

	if (this->pending == at_Attack)
		return this->attack(this->pending_x, this->pending_y);

	if (this->pending == at_Gather)
		return this->gather(this->pending_x, this->pending_y);

	if (this->pending == at_Build)
		return this->build(this->pending_x, this->pending_y, this->pending_build);

	return false;
}

std::string
Unit::getPopis() {
	std::ostringstream out;
	out << this->popis << " (" << this->hitpoints << ")";
	return out.str();
}
