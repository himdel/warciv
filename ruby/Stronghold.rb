# not ruby yet!

#include "TownHall.hpp"

class Stronghold : public TownHall {
public:
	Stronghold(Player *owner) : TownHall("Stronghold", owner) {
		this->type = bt_Stronghold;
		this->hitpoints = 1400;
		owner->addScore(100);
	}

	static Building *create(Player *owner) { return new Stronghold(owner); }
};

