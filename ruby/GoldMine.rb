# not ruby yet!

#include "Resource.hpp"

class GoldMine : public Resource {
public:
	GoldMine() : Resource("GoldMine") {}

	int gather(int amount, Player *p) {
		amount = Resource::gather(amount);
		p->addGold(amount);
		return amount;
	}
};

