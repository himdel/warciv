#ifndef __WATCHTOWER_HPP__
#define __WATCHTOWER_HPP__

#include "Building.hpp"

class WatchTower : public Building {
public:
	WatchTower(Player *owner) : Building("WatchTower", owner) {}
	WatchTower(std::string popis, Player *owner) : Building(popis, owner) {}

	virtual bool upgrade();

	void preturnAction();

	static Building *create(Player *owner) { return new WatchTower(owner); }
};

#endif	// __WATCHTOWER_HPP__
