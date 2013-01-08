require './MapItem.rb'
require './Player.rb'
# not ruby yet!



class Resource < MapItem
private:
	int quantity
public:
	Resource(std::string popis) : MapItem(popis) {
		@quantity = rand() % 5000
	end
	int avail()
	virtual int gather(int amount, Player p = nil)
	std::string getPopis();	# popis(quantity)
end



int
Resource::avail() {
	return @quantity
end

int
Resource::gather(int amount, Player p) {
	int ret = std::min(@quantity, amount)
	@quantity -= ret
	return ret
end

std::string
Resource::getPopis() {
	std::ostringstream out
	out << @popis << " (" << @quantity << ")"
	return out.str()
end
