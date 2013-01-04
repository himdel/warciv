#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include <vector>
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
	vector<Unit *> units;
	vector<Building *> buildings;
	int gold;
	int wood;
	int score;	// TODO incerement somewhere
	Game *game;

public:
	Player(string name, Game *game);
	int getScore();
	string getName();

	const vector<Unit *> getUnits(UnitType ut = ut_Any);
	void addUnit(Unit *u);
	void delUnit(Unit *u);

	const vector<Building *> getBuildings(BuildingType bt = bt_Any);
	void addBuilding(Building *b);
	void delBuilding(Building *b);

	const vector<Player *> getEnemies();

	int getGold();
	int getWood();
	void addGold(int quantity);
	void addWood(int quantity);
	bool cost(int gold, int wood);
};

#endif	// __PLAYER_HPP__
