require './Building.rb'
# not ruby yet!


class TownHall < Building
	TownHall(string popis, Player owner) : Building(popis, owner) {}
	TownHall(Player owner) : Building("TownHall", owner) {
		@type = bt_TownHall
		@hitpoints = 1200
		owner.addScore(200)
	end

	 BuildingType getType() { return bt_TownHall; }
	static Building create(Player owner) { return TownHall.new(owner); }
end

