require './Unit.rb'
# not ruby yet!


class Axethrower < Unit
	Axethrower(owner) : Unit("Axethrower", owner) {
		@hitpoints = 40
		@attack_damage = rand() % 7 + 3 + 6 * (rand() % 2);	# 3-9 + 6
		@attack_range = 3
		owner.addScore(10)
	end


	const set<ActionType> availActions() {
		return set<ActionType>({ at_None, at_Move, at_Attack })
	end
end

