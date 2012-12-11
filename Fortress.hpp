#ifndef __FORTRESS_HPP__
#define __FORTRESS_HPP__

class Fortress : public TownHall {
public:
	Fortress() : MapItem("Fortress") {}
	virtual bool upgrade();
};

#endif	// __FORTRESS_HPP__
