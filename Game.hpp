#ifndef __GAME_HPP__
#define __GAME_HPP__

#include "Map.hpp"
#include "MapItem.hpp"
#include "Player.hpp"

class Game {
private:
	Map<MapItem> *map;
	Player *players[2];

public:
	Game (int w, int h, std::string p1, std::string p2);
};

#endif	// __GAME_HPP__
