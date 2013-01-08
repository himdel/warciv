# not ruby yet!

#include "TownHall.hpp"

class Fortress : public TownHall {
public:
	Fortress(Player *owner) : TownHall("Fortress", owner) {
		this->type = bt_Fortress;
		this->hitpoints = 1600;
		owner->addScore(100);
	}

	static Building *create(Player *owner) { return new Fortress(owner); }
};

