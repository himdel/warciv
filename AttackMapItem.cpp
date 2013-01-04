#include "AttackMapItem.hpp"
#include "Unit.hpp"
#include "Building.hpp"

void
AttackMapItem::damage(int hitpoints) {
	this->hitpoints -= min(this->hitpoints, hitpoints);

	if (this->hitpoints == 0)
		this->remove();
}


bool
AttackMapItem::attack() {
	bool bb = false;
	for (Player *e : this->owner->getEnemies()) {
		for (Unit *u : e->getUnits())
			if (this->distance(u) <= this->attack_range)
				bb |= AttackMapItem::attack(u);

		for (Building *b : e->getBuildings())
			if (this->distance(b) <= this->attack_range)
				bb |= AttackMapItem::attack(b);
	}
	return bb;
}

bool
AttackMapItem::attack(int x, int y) {
	MapItem *i = this->map->get(x, y);
	if (!i)
		return false;

	AttackMapItem *a = dynamic_cast<AttackMapItem *>(i);
	if (!a)
		return false;

	return this->attack(a);
}

bool
AttackMapItem::attack(AttackMapItem *i) {
	if (!this->attack_damage || !this->attack_range)
		return false;

	if (this->distance(i->x, i->y) > this->attack_range)
		return false;

	//TODO cast utoceni s porovnani attack_*, pozice
	return true;
}
