#ifndef __PEON_HPP__
#define __PEON_HPP__

#include "Unit.hpp"

class Peon : public Unit {
public:
	Peon() : MapItem("Peon") {}
	bool gather(int x, int y);
	bool build(int x, int y, BuildingType b);
};

#endif	// __PEON_HPP__
