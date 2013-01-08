#ifndef __AXETHROWER_HPP__
#define __AXETHROWER_HPP__

#include "Unit.hpp"

class Axethrower : public Unit {
public:
	Axethrower(Player *owner) : Unit("Axethrower", owner) {
		this->hitpoints = 40;
		this->attack_damage = rand() % 7 + 3 + 6 * (rand() % 2);	// 3-9 + 6
		this->attack_range = 3;
		owner->addScore(10);
	}

	static Unit *create(Player *owner) { return new Axethrower(owner); }

	const set<ActionType> availActions() {
		return set<ActionType>({ at_None, at_Move, at_Attack });
	}
};

#endif	// __AXETHROWER_HPP__
