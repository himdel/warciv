#include "WatchTower.hpp"

void
WatchTower::preturnAction() {
	for (Player *e : this->owner->getEnemies()) {
		for (Unit *u : e->getUnits())
			if (this->distance(u) <= this->attack_range)
				AttackMapItem::attack(u->x, u->y);

		for (Building *b : e->getUnits())
			if (this->distance(b) <= this->attack_range)
				AttackMapItem::attack(b->x, b->y);
	}
}
