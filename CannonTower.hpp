#ifndef __CANNONTOWER_HPP__
#define __CANNONTOWER_HPP__

class CannonTower : public WatchTower {
public:
	CannonTower() : MapItem("CannonTower") {}
	virtual bool upgrade();
};

#endif	// __CANNONTOWER_HPP__
