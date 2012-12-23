#include "buildings.hpp"
#include "TownHall.hpp"
#include "Stronghold.hpp"
#include "Fortress.hpp"
#include "Farm.hpp"
#include "Barracks.hpp"
#include "WatchTower.hpp"
#include "GuardTower.hpp"
#include "CannonTower.hpp"

BuildingData buildings[] = {
	{ bt_TownHall, TownHall::create, "TownHall", 1 },
	{ bt_Stronghold, Stronghold::create, "Stronghold", 0 },
	{ bt_Fortress, Fortress::create, "Fortress", 0 },
	{ bt_Farm, Farm::create, "Farm", 1 },
	{ bt_Barracks, Barracks::create, "Barracks", 1 },
	{ bt_WatchTower, WatchTower::create, "WatchTower", 1 },
	{ bt_GuardTower, GuardTower::create, "GuardTower", 0 },
	{ bt_CannonTower, CannonTower::create, "CannonTower", 0 },
};
