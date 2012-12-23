#include "Forest.hpp"


int
Forest::gather(int amount, Player *p) {
	amount = Resource::gather(amount);
	p->addWood(amount);
}
