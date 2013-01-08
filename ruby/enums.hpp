#ifndef __ENUMS_HPP__
#define __ENUMS_HPP__

enum BuildingType {
	bt_Any = 0,
	bt_TownHall,
	bt_Stronghold,
	bt_Fortress,
	bt_Farm,
	bt_Barracks,
	bt_WatchTower,
	bt_GuardTower,
	bt_CannonTower,
};

enum UnitType {
	ut_Any = 0,
	ut_Peon,
	ut_Grunt,
	ut_Axethrower,
};

enum ActionType {
	at_None = 0,
	at_Move,
	at_Attack,
	at_Gather,
	at_Build,
};

#endif	// __ENUMS_HPP__
