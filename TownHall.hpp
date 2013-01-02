#ifndef __TOWNHALL_HPP__
#define __TOWNHALL_HPP__

#include "Building.hpp"

class TownHall : public Building {
public:
	TownHall(Player *owner) : Building("TownHall", owner) { this->type = bt_TownHall; }
	TownHall(std::string popis, Player *owner) : Building(popis, owner) {}

	static Building *create(Player *owner) { return new TownHall(owner); }
};

#endif	// __TOWNHALL_HPP__
