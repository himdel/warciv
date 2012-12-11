#ifndef __WATCHTOWER_HPP__
#define __WATCHTOWER_HPP__

#include "Building.hpp"

class WatchTower : public Building {
public:
	WatchTower() : Building("WatchTower") {}
	WatchTower(std::string popis) : Building(popis) {}

	virtual bool upgrade();

	bool preturnAction();

	static Building *create() { return new WatchTower(); }
};

#endif	// __WATCHTOWER_HPP__
