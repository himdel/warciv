# not ruby yet!

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

#include <algorithm>
#include "Player.hpp"
#include "Game.hpp"
#include "Peon.hpp"
#include "TownHall.hpp"
#include "Stronghold.hpp"
#include "Fortress.hpp"


Player::Player(string name, Game *game) {
	this->name = name;
	this->gold = 2400;
	this->wood = 1200;
	this->score = 0;
	this->game = game;

	Unit *peon = new Peon(this);
	auto map = game->getMap();
	pair<int, int> empty = map->closestEmpty(rand() % map->getWidth(), rand() % map->getHeight());
	peon->place(map, empty.first, empty.second);
	this->addUnit(peon);
}

int
Player::getScore() {
	return this->score;
}

string
Player::getName() {
	if (this == NULL)
		return "(none)";
	return this->name;
}

const vector<Unit *>
Player::getUnits() {
	return this->units;
}

void
Player::addUnit(Unit *u) {
	this->units.push_back(u);
}

void
Player::delUnit(Unit *u) {
	this->units.erase(std::find(this->units.begin(), this->units.end(), u));
}

const vector<Building *>
Player::getBuildings() {
	return this->buildings;
}

void
Player::addBuilding(Building *b) {
	this->buildings.push_back(b);
}

void
Player::delBuilding(Building *b) {
	this->buildings.erase(std::find(this->buildings.begin(), this->buildings.end(), b));
}

int
Player::getGold() {
	return this->gold;
}

int
Player::getWood() {
	return this->wood;
}

void
Player::addGold(int quantity) {
	this->gold += quantity;
}

void
Player::addWood(int quantity) {
	this->wood += quantity;
}

bool
Player::cost(int gold, int wood) {
	if ((this->gold < gold) || (this->wood < wood))
		return false;

	this->gold -= gold;
	this->wood -= wood;
	return true;
}

const vector<Player *>
Player::getEnemies() {
	vector<Player *> enemies;
	for (Player *p : this->game->getPlayers())
		if (p != this)
			enemies.push_back(p);
	return enemies;
}

bool
Player::isAlive() {
	return this->buildings.size() || this->units.size();
}

int
Player::addScore(int s) {
	this->score += s;
	return this->score;
}

int
Player::getGatherSpeed() {
	int gs = 10;
	for (Building *b: this->buildings) {
		if (dynamic_cast<TownHall *>(b))
			gs = max(gs, 40);
		if (dynamic_cast<Stronghold *>(b))
			gs = max(gs, 50);
		if (dynamic_cast<Fortress *>(b))
			gs = max(gs, 75);
	}
	return gs;
}
