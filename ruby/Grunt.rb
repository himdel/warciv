require './Unit.rb'
# not ruby yet!


class Grunt < Unit
	Grunt(owner) : Unit("Grunt", owner) {
		@hitpoints = 60
		@attack_damage = 6 + 3 * (rand() % 2);	# 6 + 3
		@attack_range = 1
		owner.addScore(20)
	end

	const set<ActionType> availActions() {
		return set<ActionType>({ at_None, at_Move, at_Attack })
	end

end

