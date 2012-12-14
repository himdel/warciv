#ifndef __BARRACKS_HPP__
#define __BARRACKS_HPP__

#include "Building.hpp"

class Barracks : public Building {
public:
	Barracks(Player *owner) : Building("Barracks", owner) {}
	bool create(UnitType u);

	static Building *create() { return new Barracks(); }
};

#endif	// __BARRACKS_HPP__
