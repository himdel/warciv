#ifndef __GUARDTOWER_HPP__
#define __GUARDTOWER_HPP__

class GuardTower : public WatchTower {
public:
	GuardTower() : MapItem("GuardTower") {}
	virtual bool upgrade();

	static Building *create();
};

#endif	// __GUARDTOWER_HPP__
