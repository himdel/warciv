#ifndef __UNITS_HPP__
#define __UNITS_HPP__

#include "enums.hpp"
#include "Unit.hpp"

struct UnitData {
	UnitType type;
	Unit *(*make)(Player *);
	std::string name;
	BuildingType where;
	int gold;
	int wood;
};

extern UnitData units[];

#endif	// __UNITS_HPP__
