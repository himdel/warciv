require './Building.rb'
# not ruby yet!


class TownHall < Building
	TownHall(popis, owner) : Building(popis, owner) {}
	TownHall(owner) : Building("TownHall", owner) {
		@type = bt_TownHall
		@hitpoints = 1200
		owner.addScore(200)
	end

	 BuildingType getType() { return bt_TownHall; }
end

