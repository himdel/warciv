#ifndef __PEON_HPP__
#define __PEON_HPP__

#include "Unit.hpp"

class Peon : public Unit {
public:
	Peon() : Unit("Peon") {}
	bool gather(int x, int y);
	bool build(int x, int y, BuildingType b);

	static Unit *create() { return new Peon(); }
};

#endif	// __PEON_HPP__
