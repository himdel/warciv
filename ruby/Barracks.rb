# not ruby yet!

#include "Building.hpp"

class Barracks : public Building {
public:
	Barracks(Player *owner) : Building("Barracks", owner) {
		this->type = bt_Barracks;
		this->hitpoints = 800;
		owner->addScore(80);
	}

	static Building *create(Player *owner) { return new Barracks(owner); }
};

