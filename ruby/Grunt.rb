
#include "Unit.hpp"

class Grunt : public Unit {
public:
	Grunt(Player *owner) : Unit("Grunt", owner) {
		this->hitpoints = 60;
		this->attack_damage = 6 + 3 * (rand() % 2);	// 6 + 3
		this->attack_range = 1;
		owner->addScore(20);
	}

	const set<ActionType> availActions() {
		return set<ActionType>({ at_None, at_Move, at_Attack });
	}

	static Unit *create(Player *owner) { return new Grunt(owner); }
};

