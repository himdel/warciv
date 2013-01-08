require './MapItem.rb'
require './Player.rb'
# not ruby yet!



class Resource < MapItem
	Resource(popis) : MapItem(popis) {
		@quantity = rand() % 5000
	end
	int avail()
	virtual int gather(int amount, Player p = nil)
	string getPopis();	# popis(quantity)
end



def avail()
	return @quantity
end

def gather(amount, p)
	int ret = min(@quantity, amount)
	@quantity -= ret
	return ret
end

def getPopis()
	out << @popis << " (" << @quantity << ")"
	return out.str()
end
