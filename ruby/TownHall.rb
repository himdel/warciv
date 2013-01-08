# not ruby yet!

require './Building.rb'

class TownHall < Building
public:
	TownHall(std::string popis, Player owner) : Building(popis, owner) {}
	TownHall(Player owner) : Building("TownHall", owner) {
		@type = bt_TownHall
		@hitpoints = 1200
		owner.addScore(200)
	}

	 BuildingType getType() { return bt_TownHall; }
	static Building create(Player owner) { return TownHall.new(owner); }
end

