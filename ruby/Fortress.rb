# not ruby yet!

require './TownHall.rb'

class Fortress < TownHall
public:
	Fortress(Player owner) : TownHall("Fortress", owner) {
		@type = bt_Fortress
		@hitpoints = 1600
		owner.addScore(100)
	}

	static Building create(Player owner) { return Fortress.new(owner); }
end

