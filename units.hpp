#ifndef __UNITS_HPP__
#define __UNITS_HPP__

#include "enums.hpp"
#include "Unit.hpp"

struct UnitData {
	UnitType type;
	Unit *(*make)();
	std::string name;
	BuildingType where;
};

extern UnitData units[];

#endif	// __UNITS_HPP__
