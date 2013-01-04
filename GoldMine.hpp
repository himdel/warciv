#ifndef __GOLDMINE_HPP__
#define __GOLDMINE_HPP__

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

#endif	// __GOLDMINE_HPP__
