#include <algorithm>
#include "Player.hpp"
#include "Game.hpp"


Player::Player(string name, Game *game) {
	this->name = name;
	this->gold = 1000;
	this->wood = 500;
	this->score = 0;
	this->game = game;
}

int
Player::getScore() {
	return this->score;
}

string
Player::getName() {
	return this->name;
}

const vector<Unit *>
Player::getUnits(UnitType ut) {
	//TODO ut
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
Player::getBuildings(BuildingType bt) {
	// TODO bt
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
