#ifndef __GRUNT_HPP__
#define __GRUNT_HPP__

#include "Unit.hpp"

class Grunt : public Unit {
public:
	Grunt(Player *owner) : Unit("Grunt", owner) {
		this->hitpoints = 60;
		this->attack_damage = 6 + 3 * (rand() % 2);	// 6 + 3
		this->attack_range = 1;
	}

	static Unit *create(Player *owner) { return new Grunt(owner); }
};

#endif	// __GRUNT_HPP__
