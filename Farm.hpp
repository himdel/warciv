#ifndef __FARM_HPP__
#define __FARM_HPP__

#include "Building.hpp"

class Farm : public Building {
public:
	Farm(Player *owner) : Building("Farm", owner) {
		this->type = bt_Farm;
		this->hitpoints = 400;
		this->feeds = 4;
	}

	static Building *create(Player *owner) { return new Farm(owner); }
};

#endif	// __FARM_HPP__
