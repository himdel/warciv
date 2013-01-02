#ifndef __STRONGHOLD_HPP__
#define __STRONGHOLD_HPP__

#include "TownHall.hpp"

class Stronghold : public TownHall {
public:
	Stronghold(Player *owner) : TownHall("Stronghold", owner) { this->type = bt_Stronghold; }

	static Building *create(Player *owner);
};

#endif	// __STRONGHOLD_HPP__
