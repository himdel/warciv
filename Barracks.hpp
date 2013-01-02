#ifndef __BARRACKS_HPP__
#define __BARRACKS_HPP__

#include "Building.hpp"

class Barracks : public Building {
public:
	Barracks(Player *owner) : Building("Barracks", owner) { this->type = bt_Barracks; }

	static Building *create(Player *owner) { return new Barracks(owner); }
};

#endif	// __BARRACKS_HPP__
