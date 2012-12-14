#ifndef __BUILDING_HPP__
#define __BUILDING_HPP__

#include <stdbool.h>
#include "enums.hpp"
#include "MapItem.hpp"

class Building : public MapItem {
protected:
	Player *owner;

public:
	Building(std::string popis, Player *p) : MapItem(popis), owner(p) {}

	virtual bool upgrade();
	virtual bool create(UnitType u);

	virtual bool preturnAction() {}

	virtual std::string getPopis();
};

#endif	// __BUILDING_HPP__
