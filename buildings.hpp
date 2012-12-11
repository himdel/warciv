#ifndef __UNITS_HPP__
#define __UNITS_HPP__

#include "Building.hpp"

enum BuildingType {
	bt_TownHall,
	bt_Stronghold,
	bt_Fortress,
	bt_Farm,
	bt_Barracks,
	bt_WatchTower,
	bt_GuardTower,
	bt_CannonTower,
};

struct BuildingData {
	BuildingType type;
	Building *(*make)();
	string name;
	int base;	// base building, buildable by peons
};

extern BuildingData buildings[];

#endif	// __UNITS_HPP__
