# not ruby yet!

require './enums.rb'
require './Building.rb'

struct BuildingData {
	BuildingType type;
	Building *(*make)(Player *owner);
	std::string name;
	BuildingType base;	# base building, or bt_Any if buildable by peons
	int gold;
	int wood;
end

extern BuildingData buildings[];
extern unsigned buildings_count;

require './buildings.rb'
require './TownHall.rb'
require './Stronghold.rb'
require './Fortress.rb'
require './Farm.rb'
require './Barracks.rb'
require './WatchTower.rb'
require './GuardTower.rb'
require './CannonTower.rb'

BuildingData buildings[] = {
	{ bt_TownHall, TownHall::create, "TownHall", bt_Any, 1200, 800 },
	{ bt_Stronghold, Stronghold::create, "Stronghold", bt_TownHall, 2000, 1000 },
	{ bt_Fortress, Fortress::create, "Fortress", bt_Stronghold, 2500, 1200 },
	{ bt_Farm, Farm::create, "Farm", bt_Any, 500, 250 },
	{ bt_Barracks, Barracks::create, "Barracks", bt_Any, 700, 400 },
	{ bt_WatchTower, WatchTower::create, "WatchTower", bt_Any, 550, 150 },
	{ bt_GuardTower, GuardTower::create, "GuardTower", bt_WatchTower, 550, 150 },
	{ bt_CannonTower, CannonTower::create, "CannonTower", bt_GuardTower, 550, 150 },
end

unsigned buildings_count = sizeof(buildings) / sizeof(BuildingData);
