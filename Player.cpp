#include "Player.hpp"


Player::Player(string name) {
	this->name = name;
	this->gold = 1000;
	this->wood = 500;
	this->score = 0;
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
