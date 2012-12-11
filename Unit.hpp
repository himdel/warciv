#ifndef __UNIT_HPP__
#define __UNIT_HPP__

#include <stdbool.h>
#include "MapItem.hpp"
#include "Game.hpp"

class Unit : public MapItem {
public:
	Unit() : MapItem("??Unit??") {}
	bool move(int x, int y);
	virtual bool gather(int x, int y);
	virtual bool build(int x, int y, BuildingType b);
	virtual bool attack(int x, int y);
	bool stop();
};

#endif	// __UNIT_HPP__
