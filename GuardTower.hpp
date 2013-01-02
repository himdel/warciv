#ifndef __GUARDTOWER_HPP__
#define __GUARDTOWER_HPP__

#include "WatchTower.hpp"

class GuardTower : public WatchTower {
public:
	GuardTower(Player *owner) : WatchTower("GuardTower", owner) {}
	virtual bool upgrade();

	static Building *create(Player *owner) { return new GuardTower(owner); }
};

#endif	// __GUARDTOWER_HPP__
