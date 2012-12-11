#ifndef __GRUNT_HPP__
#define __GRUNT_HPP__

#include "Unit.hpp"

class Grunt : public Unit {
public:
	Grunt() : Unit("Grunt") {}
	bool attack(int x, int y);

	static Unit *create() { return new Grunt(); }
};

#endif	// __GRUNT_HPP__
