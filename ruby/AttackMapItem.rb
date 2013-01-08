
#include "MapItem.hpp"
class Player;

class AttackMapItem : public MapItem {
protected:
	Player *owner;
	int hitpoints;
	int attack_damage;
	int attack_range;

public:
	AttackMapItem(std::string popis, Player *p) : MapItem(popis), owner(p) {
		this->hitpoints = 0;
		this->attack_damage = 0;
		this->attack_range = 0;
	}

	virtual void damage(int hitpoints);

	virtual bool attack();
	virtual bool attack(int x, int y);
	virtual bool attack(AttackMapItem *i);
};

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

// do not use i afterwards
bool
AttackMapItem::attack(AttackMapItem *i) {
	if (i == this)
		return false;

	if (!this->attack_damage || !this->attack_range)
		return false;

	if (this->distance(i->x, i->y) > this->attack_range)
		return false;

	double d = 2;
	if (this->distance(i->x, i->y) - 1 > this->attack_range / 2.0)
		d = 1;

	i->damage( rand() % ((int) round(this->attack_damage * d)) );
	return true;
}
