#ifndef __BUILDINGS_HPP__
#define __BUILDINGS_HPP__

#include "enums.hpp"
#include "Building.hpp"

struct BuildingData {
	BuildingType type;
	Building *(*make)(Player *owner);
	std::string name;
	BuildingType base;	// base building, or bt_Any if buildable by peons
	int gold;
	int wood;
};

extern BuildingData buildings[];
extern unsigned buildings_count;

#endif	// __BUILDINGS_HPP__
