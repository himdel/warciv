#ifndef __TOWNHALL_HPP__
#define __TOWNHALL_HPP__

class TownHall : public Building {
public:
	bool create(UnitType u);
	virtual bool upgrade();
};

#endif	// __TOWNHALL_HPP__
