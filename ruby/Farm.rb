# not ruby yet!

#include "Building.hpp"

class Farm : public Building {
public:
	Farm(Player *owner) : Building("Farm", owner) {
		this->type = bt_Farm;
		this->hitpoints = 400;
		this->feeds = 4;
		owner->addScore(100);	// feeds nedodelano, zvyseno score
	}

	static Building *create(Player *owner) { return new Farm(owner); }
};

