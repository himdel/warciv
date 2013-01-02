#ifndef __CANNONTOWER_HPP__
#define __CANNONTOWER_HPP__

#include "WatchTower.hpp"

class CannonTower : public WatchTower {
public:
	CannonTower(Player *owner) : WatchTower("CannonTower", owner) { this->type = bt_CannonTower; }

	static Building *create(Player *owner) { return new CannonTower(owner); }
};

#endif	// __CANNONTOWER_HPP__
