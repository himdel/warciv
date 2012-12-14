#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include <list>
#include "Unit.hpp"
#include "Building.hpp"

using namespace std;

class Player {
private:
	string name;
	list<Unit *> units;
	list<Building *> buildings;
	int gold;
	int wood;
	int score;

public:
	Player(string name);
	int getScore();
	string getName();

	list<Unit *> getUnits(UnitType ut);
	void addUnit(Unit *u);
	void delUnit(Unit *u);

	list<Building *> getBuildings(BuildingType bt);
	void addBuilding(Building *b);
	void delBuilding(Building *b);

	int getGold();
	int getWood();
};

#endif	// __PLAYER_HPP__
