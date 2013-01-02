#ifndef __FORTRESS_HPP__
#define __FORTRESS_HPP__

#include "TownHall.hpp"

class Fortress : public TownHall {
public:
	Fortress(Player *owner) : TownHall("Fortress", owner) { this->type = bt_Fortress; }

	static Building *create(Player *owner);
};

#endif	// __FORTRESS_HPP__
