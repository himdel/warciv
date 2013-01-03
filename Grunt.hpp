#ifndef __GRUNT_HPP__
#define __GRUNT_HPP__

#include "Unit.hpp"

class Grunt : public Unit {
public:
	Grunt(Player *owner) : Unit("Grunt", owner) {
		this->hp = 60;
		this->damage = 6 + 3 * (rand() % 2);	// 6 + 3
		this->range = 1;
	}
	bool attack(int x, int y);

	static Unit *create(Player *owner) { return new Grunt(owner); }
};

#endif	// __GRUNT_HPP__
