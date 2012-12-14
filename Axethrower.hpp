#ifndef __AXETHROWER_HPP__
#define __AXETHROWER_HPP__

#include "Unit.hpp"

class Axethrower : public Unit {
public:
	Axethrower(Player *owner) : Unit("Axethrower", owner) {}
	bool attack(int x, int y);

	static Unit *create(Player *owner) { return new Axethrower(owner); }
};

#endif	// __AXETHROWER_HPP__
