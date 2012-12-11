#ifndef __CANNONTOWER_HPP__
#define __CANNONTOWER_HPP__

#include "WatchTower.hpp"

class CannonTower : public WatchTower {
public:
	CannonTower() : MapItem("CannonTower") {}
	virtual bool upgrade();

	static Building *create();
};

#endif	// __CANNONTOWER_HPP__
