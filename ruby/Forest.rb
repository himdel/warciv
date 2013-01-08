
#include "Resource.hpp"

class Forest : public Resource {
public:
	Forest() : Resource("Forest") {}

	int gather(int amount, Player *p) {
		amount = Resource::gather(amount);
		p->addWood(amount);
		return amount;
	}
};

