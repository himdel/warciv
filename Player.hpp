#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include <list>
class Player;
class Unit;
class Building;
class Game;
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
	Game *game;

public:
	Player(string name, Game *game);
	int getScore();
	string getName();

	const list<Unit *> getUnits(UnitType ut);
	void addUnit(Unit *u);
	void delUnit(Unit *u);

	const list<Building *> getBuildings(BuildingType bt);
	void addBuilding(Building *b);
	void delBuilding(Building *b);

	const list<Player *> getEnemies();

	int getGold();
	int getWood();
	void addGold(int quantity);
	void addWood(int quantity);
	bool cost(int gold, int wood);
};

#endif	// __PLAYER_HPP__
