#include "AttackMapItem.hpp"

void
AttackMapItem::damage(int hitpoints) {
	this->hitpoints -= min(this->hitpoints, hitpoints);

	if (this->hitpoints == 0)
		this->remove();
}

bool
AttackMapItem::attack(int x, int y) {
	if (!this->attack_damage || !this->attack_range)
		return false;

	if (this->distance(x, y) > this->attack_range)
		return false;

	//TODO cast utoceni s porovnani attack_*, pozice
	return true;
}

