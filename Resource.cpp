#include <sstream>
#include "Resource.hpp"


int
Resource::avail() {
	return this->quantity;
}

int
Resource::gather(int amount) {
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
