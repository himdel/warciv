require './Building.rb'
# not ruby yet!


class Barracks < Building
	Barracks(owner) : Building("Barracks", owner) {
		@type = bt_Barracks
		@hitpoints = 800
		owner.addScore(80)
	end

end

