#ifndef __FORTRESS_HPP__
#define __FORTRESS_HPP__

#include "TownHall.hpp"

class Fortress : public TownHall {
public:
	Fortress(Player *owner) : TownHall("Fortress", owner) {
		this->type = bt_Fortress;
		this->hitpoints = 1600;
	}

	static Building *create(Player *owner) { return new Fortress(owner); }
};

#endif	// __FORTRESS_HPP__
