# not ruby yet!

require './MapItem.rb'
require './Player.rb'


class Resource < MapItem
private:
	int quantity
public:
	Resource(std::string popis) : MapItem(popis) {
		@quantity = rand() % 5000
	}
	int avail()
	virtual int gather(int amount, Player *p = NULL)
	std::string getPopis();	# popis(quantity)
end

require './Resource.rb'


int
Resource::avail() {
	return @quantity
}

int
Resource::gather(int amount, Player *p) {
	int ret = std::min(@quantity, amount)
	@quantity -= ret
	return ret
}

std::string
Resource::getPopis() {
	std::ostringstream out
	out << @popis << " (" << @quantity << ")"
	return out.str()
}
