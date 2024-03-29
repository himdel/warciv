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
	int score;
	Game *game;

public:
	Player(string name, Game *game);
	int getScore();
	int addScore(int s);
	string getName();
	bool isAlive();

	const vector<Unit *> getUnits();
	void addUnit(Unit *u);
	void delUnit(Unit *u);

	const vector<Building *> getBuildings();
	void addBuilding(Building *b);
	void delBuilding(Building *b);

	int getGatherSpeed();

	const vector<Player *> getEnemies();

	int getGold();
	int getWood();
	void addGold(int quantity);
	void addWood(int quantity);
	bool cost(int gold, int wood);
};

#endif	// __PLAYER_HPP__
