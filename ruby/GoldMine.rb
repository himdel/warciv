# not ruby yet!

require './Resource.rb'

class GoldMine < Resource
public:
	GoldMine() : Resource("GoldMine") {}

	int gather(int amount, Player *p) {
		amount = Resource::gather(amount);
		p->addGold(amount);
		return amount;
	}
end

