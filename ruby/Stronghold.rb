require './TownHall.rb'
# not ruby yet!


class Stronghold < TownHall
	Stronghold(owner) : TownHall("Stronghold", owner) {
		@type = bt_Stronghold
		@hitpoints = 1400
		owner.addScore(100)
	end

end

