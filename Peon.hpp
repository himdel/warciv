#ifndef __PEON_HPP__
#define __PEON_HPP__

#include "Unit.hpp"

class Peon : public Unit {
private:
	bool cargo;

public:
	Peon(Player *owner) : Unit("Peon", owner) {
		this->hitpoints = 30;
		this->cargo = false;
	}

	bool gather(int x, int y);
	bool build(int x, int y, BuildingType b);

	static Unit *create(Player *owner) { return new Peon(owner); }
};

#endif	// __PEON_HPP__
