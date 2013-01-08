require './Building.rb'
# not ruby yet!


class Farm < Building
public:
	Farm(Player owner) : Building("Farm", owner) {
		@type = bt_Farm
		@hitpoints = 400
		@feeds = 4
		owner.addScore(100);	# feeds nedodelano, zvyseno score
	end

	static Building create(Player owner) { return Farm.new(owner); }
end

