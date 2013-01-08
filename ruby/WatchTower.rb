require './Building.rb'
# not ruby yet!


class WatchTower < Building
public:
	WatchTower(string popis, Player owner) : Building(popis, owner) {}
	WatchTower(Player owner) : Building("WatchTower", owner) {
		@type = bt_WatchTower
		@hitpoints = 100
		@attack_range = 2
		@attack_damage = 1
		owner.addScore(50)
	end

	void preturnAction() { self.attack(); }

	static Building create(Player owner) { return WatchTower.new(owner); }
end

