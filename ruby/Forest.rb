require './Resource.rb'
# not ruby yet!


class Forest < Resource
	Forest() : Resource("Forest") {}

	def gather(amount, p)
		amount = Resource::gather(amount)
		p.addWood(amount)
		return amount
	end
end

