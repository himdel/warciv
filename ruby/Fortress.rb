require './TownHall.rb'
# not ruby yet!


class Fortress < TownHall
public:
	Fortress(Player owner) : TownHall("Fortress", owner) {
		@type = bt_Fortress
		@hitpoints = 1600
		owner.addScore(100)
	end

	static Building create(Player owner) { return Fortress.new(owner); }
end

