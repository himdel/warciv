require './Building.rb'
# not ruby yet!


class Barracks < Building
	Barracks(Player owner) : Building("Barracks", owner) {
		@type = bt_Barracks
		@hitpoints = 800
		owner.addScore(80)
	end

	static Building create(Player owner) { return Barracks.new(owner); }
end

