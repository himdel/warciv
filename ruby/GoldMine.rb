require './Resource.rb'
# not ruby yet!


class GoldMine < Resource
	GoldMine() : Resource("GoldMine") {}

	int gather(int amount, Player p) {
		amount = Resource::gather(amount)
		p.addGold(amount)
		return amount
	end
end

