#ifndef __FARM_HPP__
#define __FARM_HPP__

class Farm : public Building {
public:
	Farm() : MapItem("Farm") {}

	static Building *create() { return new Farm(); }
};

#endif	// __FARM_HPP__
