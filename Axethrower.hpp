#ifndef __AXETHROWER_HPP__
#define __AXETHROWER_HPP__

#include "Unit.hpp"

class Axethrower : public Unit {
public:
	Axethrower(Player *owner) : Unit("Axethrower", owner) {}
	bool attack(int x, int y);

	static Unit *create() { return new Axethrower(); }
};

#endif	// __AXETHROWER_HPP__
