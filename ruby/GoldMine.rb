require './Resource.rb'
# not ruby yet!


class GoldMine < Resource
	GoldMine() : Resource("GoldMine") {}

	def gather(int amount, Player p)
		amount = Resource::gather(amount)
		p.addGold(amount)
		return amount
	end
end

