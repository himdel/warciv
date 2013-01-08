require './TownHall.rb'
# not ruby yet!


class Fortress < TownHall
	Fortress(owner) : TownHall("Fortress", owner) {
		@type = bt_Fortress
		@hitpoints = 1600
		owner.addScore(100)
	end

	static Building create(owner) { return Fortress.new(owner); }
end

