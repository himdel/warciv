#ifndef __GAME_HPP__
#define __GAME_HPP__

#include <vector>
#include "Map.hpp"
#include "MapItem.hpp"
#include "Player.hpp"
#include "UI.hpp"

class Game {
private:
	Map<MapItem> *map;
	vector<Player *> players;
	UI *ui;

public:
	Game(int w, int h, std::string p1, std::string p2);

	void play();
	Player *winner();
	string score();

	~Game();
};

#endif	// __GAME_HPP__
