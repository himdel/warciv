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
};

#endif	// __PLAYER_HPP__
