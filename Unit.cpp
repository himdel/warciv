#include <sstream>
#include "Unit.hpp"
#include "Map.hpp"
#include "buildings.hpp"


bool
Unit::move(int x, int y) {
	auto f = [x, y] (MapItem *mi, int px, int py) { return (x == px) && (y == py); };
	list< pair<int, int> > path = this->map->closest(f, x, y);
	if (path.empty())
		return false;

	int px = path.front().first;
	int py = path.front().second;

	if (this->map->get(px, py))
		return false;

	this->remove();
	this->place(px, py);

	if (x == this->pending_x && y == this->pending_y && this->pending == at_Move)
		this->pending = at_None;

	return true;
}

bool
Unit::gather(int x, int y) {
	return false;	// done, overidden in Peon
}

bool
Unit::build(int x, int y, BuildingType b) {
	return false;	// done, overidden in Peon
}

// do not use this afterwards
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
		if (this->AttackMapItem::attack())
			return true;
		return this->move(x, y);
	}

	if (x == this->pending_x && y == this->pending_y && this->pending == at_Attack)
		this->pending = at_None;

	return AttackMapItem::attack(x, y);
}

void
Unit::stop() {
	this->queueAction();
}

void
Unit::queueAction(ActionType at, int x, int y, BuildingType bt) {
	this->pending = at;
	this->pending_build = bt;
	this->pending_x = x;
	this->pending_y = y;
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
	out << "_" << this->owner->getName()[0] << this->owner->getName()[1] << "_" << this->popis << " (" << this->hitpoints << ")";
	return out.str();
}

std::string
Unit::getDetail() {
	std::ostringstream out;
	out << this->popis << " (hp: " << this->hitpoints;
	switch (this->pending) {
		case at_Move:
			out << ", action: " << "move(" << this->pending_x << ", " << this->pending_y << ")";
			break;
		case at_Attack:
			out << ", action: " << "attack(" << this->pending_x << ", " << this->pending_y << ")";
			break;
		case at_Gather:
			out << ", action: " << "gather(" << this->pending_x << ", " << this->pending_y << ")";
			break;
		case at_Build:
			out << ", action: " << "build(" << this->pending_x << ", " << this->pending_y << ", " << buildings[this->pending_build - 1].name << ")";
			break;
		case at_None:
			out << ", no action";
	}
	out << ")";
	return out.str();
}
