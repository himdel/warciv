#ifndef __AXETHROWER_HPP__
#define __AXETHROWER_HPP__

#include "Unit.hpp"

class Axethrower : public Unit {
public:
	Axethrower(Player *owner) : Unit("Axethrower", owner) {
		this->hp = 40;
		this->damage = rand() % 7 + 3 + 6 * (rand() % 2);	// 3-9 + 6
		this->range = 4;
	}
	bool attack(int x, int y);

	static Unit *create(Player *owner) { return new Axethrower(owner); }
};

#endif	// __AXETHROWER_HPP__
