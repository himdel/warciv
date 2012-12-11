#ifndef __BARRACKS_HPP__
#define __BARRACKS_HPP__

class Barracks : public Building {
public:
	Barracks() : MapItem("Barracks") {}
	bool create(UnitType u);

	static Building *create() { return new Barracks(); }
};

#endif	// __BARRACKS_HPP__
