#ifndef __RESOURCE_HPP__
#define __RESOURCE_HPP__

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

#endif	// __RESOURCE_HPP__
