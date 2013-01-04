#include <cmath>
#include "AttackMapItem.hpp"

static double
distance(int x1, int y1, int x2, int y2) {
	int dx = fabs(x1 - x2);
	int dy = fabs(y1 - y2);
	dx *= dx;
	dy *= dy;
	return sqrt(dx + dy);
}

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

	if (distance(x, y, this->x, this->y) > this->attack_range)
		return false;

	//TODO cast utoceni s porovnani attack_*, pozice
	return true;
}

