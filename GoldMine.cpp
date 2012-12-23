#include "GoldMine.hpp"


int
GoldMine::gather(int amount, Player *p) {
	amount = Resource::gather(amount);
	p->addGold(amount);
}
