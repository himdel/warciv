require './MapItem.rb'
require './Player.rb'
# not ruby yet!



class Resource < MapItem
	Resource(string popis) : MapItem(popis) {
		@quantity = rand() % 5000
	end
	int avail()
	virtual int gather(int amount, Player p = nil)
	string getPopis();	# popis(quantity)
end



avail() {
	return @quantity
end

gather(int amount, Player p) {
	int ret = min(@quantity, amount)
	@quantity -= ret
	return ret
end

getPopis() {
	out << @popis << " (" << @quantity << ")"
	return out.str()
end
