#ifndef __STRONGHOLD_HPP__
#define __STRONGHOLD_HPP__

class Stronghold : public TownHall {
public:
	Stronghold() : MapItem("Stronghold") {}
	virtual bool upgrade();
};

#endif	// __STRONGHOLD_HPP__
