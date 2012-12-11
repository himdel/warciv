#ifndef __WATCHTOWER_HPP__
#define __WATCHTOWER_HPP__

class WatchTower : public Building {
public:
	WatchTower() : MapItem("WatchTower") {}
	virtual bool upgrade();

	bool preturnAction();
};

#endif	// __WATCHTOWER_HPP__
