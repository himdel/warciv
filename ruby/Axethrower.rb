require './Unit.rb'
# not ruby yet!


class Axethrower < Unit
public:
	Axethrower(Player owner) : Unit("Axethrower", owner) {
		@hitpoints = 40
		@attack_damage = rand() % 7 + 3 + 6 * (rand() % 2);	# 3-9 + 6
		@attack_range = 3
		owner.addScore(10)
	}

	static Unit create(Player owner) { return Axethrower.new(owner); }

	const set<ActionType> availActions() {
		return set<ActionType>({ at_None, at_Move, at_Attack })
	}
end

