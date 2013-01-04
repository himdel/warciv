#ifndef __CANNONTOWER_HPP__
#define __CANNONTOWER_HPP__

#include "WatchTower.hpp"

class CannonTower : public WatchTower {
public:
	CannonTower(Player *owner) : WatchTower("CannonTower", owner) {
		this->type = bt_CannonTower;
		this->hitpoints = 160;
		this->attack_damage = 50;
		this->attack_range = 9;
	}

	static Building *create(Player *owner) { return new CannonTower(owner); }
};

#endif	// __CANNONTOWER_HPP__
