#ifndef __STRONGHOLD_HPP__
#define __STRONGHOLD_HPP__

#include "TownHall.hpp"

class Stronghold : public TownHall {
public:
	Stronghold() : MapItem("Stronghold") {}
	virtual bool upgrade();

	static Building *create();
};

#endif	// __STRONGHOLD_HPP__
