#ifndef __BUILDING_HPP__
#define __BUILDING_HPP__

#include <stdbool.h>
#include "enums.hpp"
#include "MapItem.hpp"

class Building : public MapItem {
public:
	Building(std::string popis) : MapItem(popis) {}

	virtual bool upgrade();
	virtual bool create(UnitType u);

	virtual bool preturnAction() {}
};

#endif	// __BUILDING_HPP__
