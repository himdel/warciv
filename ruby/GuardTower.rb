require './WatchTower.rb'
# not ruby yet!


class GuardTower < WatchTower
	GuardTower(Player owner) : WatchTower("GuardTower", owner) {
		@type = bt_GuardTower
		@hitpoints = 130
		@attack_range = 4
		@attack_damage = 4 + 12 * (rand() % 2);	# 4 + 12
		owner.addScore(20)
	end

	static Building create(Player owner) { return GuardTower.new(owner); }
end

