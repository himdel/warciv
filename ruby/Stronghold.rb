require './TownHall.rb'
# not ruby yet!


class Stronghold < TownHall
	Stronghold(Player owner) : TownHall("Stronghold", owner) {
		@type = bt_Stronghold
		@hitpoints = 1400
		owner.addScore(100)
	end

	static Building create(Player owner) { return Stronghold.new(owner); }
end

