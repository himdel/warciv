require './Resource.rb'
# not ruby yet!


class GoldMine < Resource
	GoldMine() : Resource("GoldMine") {}

	def gather(amount, p)
		amount = Resource::gather(amount)
		p.addGold(amount)
		return amount
	end
end

