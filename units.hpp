#ifndef __BUILDINGS_HPP__
#define __BUILDINGS_HPP__

#include "buildings.hpp"
#include "Unit.hpp"

enum UnitType {
	ut_Peon,
	ut_Grunt,
	ut_Axethrower,
};

struct UnitData {
	UnitType type;
	Unit *(*make)();
	string name;
	BuildingType where;
};

extern UnitData units[];

#endif	// __BUILDINGS_HPP__
