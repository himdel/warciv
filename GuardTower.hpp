#ifndef __GUARDTOWER_HPP__
#define __GUARDTOWER_HPP__

class GuardTower : public WatchTower {
public:
	GuardTower() : MapItem("GuardTower") {}
	virtual bool upgrade();
};

#endif	// __GUARDTOWER_HPP__
