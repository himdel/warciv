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

const list<Unit *>
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
	this->units.remove(u);
}

const list<Building *>
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
	this->buildings.remove(b);
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

const list<Player *>
Player::getEnemies() {
	list<Player *> enemies;
	for (Player *p : this->game->getPlayers())
		if (p != this)
			enemies.push_back(p);
	return enemies;
}
