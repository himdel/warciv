require './WatchTower.rb'
# not ruby yet!


class CannonTower < WatchTower
	CannonTower(owner) : WatchTower("CannonTower", owner) {
		@type = bt_CannonTower
		@hitpoints = 160
		@attack_damage = 50
		@attack_range = 3
		owner.addScore(20)
	end

end

