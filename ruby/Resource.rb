
#include <cstdlib>
#include "MapItem.hpp"
#include "Player.hpp"


class Resource : public MapItem {
private:
	int quantity;
public:
	Resource(std::string popis) : MapItem(popis) {
		this->quantity = rand() % 5000;
	}
	int avail();
	virtual int gather(int amount, Player *p = NULL);
	std::string getPopis();	// popis(quantity)
};

#include <sstream>
#include "Resource.hpp"


int
Resource::avail() {
	return this->quantity;
}

int
Resource::gather(int amount, Player *p) {
	int ret = std::min(this->quantity, amount);
	this->quantity -= ret;
	return ret;
}

std::string
Resource::getPopis() {
	std::ostringstream out;
	out << this->popis << " (" << this->quantity << ")";
	return out.str();
}
