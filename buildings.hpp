#ifndef __BUILDINGS_HPP__
#define __BUILDINGS_HPP__

#include "enums.hpp"
#include "Building.hpp"

struct BuildingData {
	BuildingType type;
	Building *(*make)();
	std::string name;
	int base;	// base building, buildable by peons
};

extern BuildingData buildings[];

#endif	// __BUILDINGS_HPP__
