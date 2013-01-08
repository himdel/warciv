#ifndef __STRONGHOLD_HPP__
#define __STRONGHOLD_HPP__

#include "TownHall.hpp"

class Stronghold : public TownHall {
public:
	Stronghold(Player *owner) : TownHall("Stronghold", owner) {
		this->type = bt_Stronghold;
		this->hitpoints = 1400;
		owner->addScore(100);
	}

	static Building *create(Player *owner) { return new Stronghold(owner); }
};

#endif	// __STRONGHOLD_HPP__
