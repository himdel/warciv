#ifndef __RESOURCE_HPP__
#define __RESOURCE_HPP__

#include <cstdlib>
#include "MapItem.hpp"

class Resource : public MapItem {
private:
	int quantity;
public:
	Resource(std::string popis) : MapItem(popis) {
		this->quantity = rand() % 5000;
	}
	int avail();
	int gather(int amount);
	std::string getPopis();	// popis(quantity)
};

#endif	// __RESOURCE_HPP__
