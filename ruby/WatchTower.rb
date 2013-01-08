require './Building.rb'
# not ruby yet!


class WatchTower < Building
	WatchTower(popis, owner) : Building(popis, owner) {}
	WatchTower(owner) : Building("WatchTower", owner) {
		@type = bt_WatchTower
		@hitpoints = 100
		@attack_range = 2
		@attack_damage = 1
		owner.addScore(50)
	end

	void preturnAction() { self.attack(); }

	static Building create(owner) { return WatchTower.new(owner); }
end

