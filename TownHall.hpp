#ifndef __TOWNHALL_HPP__
#define __TOWNHALL_HPP__

#include "Building.hpp"

class TownHall : public Building {
public:
	TownHall() : Building("TownHall") {}
	TownHall(std::string popis) : Building(popis) {}

	bool create(UnitType u);
	virtual bool upgrade();

	static Building *create() { return new TownHall(); }
};

#endif	// __TOWNHALL_HPP__
