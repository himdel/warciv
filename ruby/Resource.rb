require './MapItem.rb'
require './Player.rb'
# not ruby yet!



class Resource < MapItem
private:
	int quantity
public:
	Resource(string popis) : MapItem(popis) {
		@quantity = rand() % 5000
	end
	int avail()
	virtual int gather(int amount, Player p = nil)
	string getPopis();	# popis(quantity)
end



int
avail() {
	return @quantity
end

int
gather(int amount, Player p) {
	int ret = min(@quantity, amount)
	@quantity -= ret
	return ret
end

string
getPopis() {
	ostringstream out
	out << @popis << " (" << @quantity << ")"
	return out.str()
end
