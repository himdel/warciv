require './Building.rb'
# not ruby yet!


class Farm < Building
	Farm(owner) : Building("Farm", owner) {
		@type = bt_Farm
		@hitpoints = 400
		@feeds = 4
		owner.addScore(100);	# feeds nedodelano, zvyseno score
	end

end

