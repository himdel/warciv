#ifndef __GAME_HPP__
#define __GAME_HPP__

#include "Game.hpp"
#include "Player.hpp"

// TODO
enum BuildingType {
};
enum UnitType {
};

class Game {
private:
	Map<MapItem> *map;
	Player *players[2];

public:
	Game (int w, int h, std::string p1, std::string p2);
};

#endif	// __GAME_HPP__
