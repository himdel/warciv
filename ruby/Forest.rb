require './Resource.rb'
# not ruby yet!


class Forest < Resource
	Forest() : Resource("Forest") {}

	int gather(int amount, Player p) {
		amount = Resource::gather(amount)
		p.addWood(amount)
		return amount
	end
end

