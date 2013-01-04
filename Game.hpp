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
	int win_score;
	int turn;

public:
	Game(int w, int h, std::string p1, std::string p2, int win_score);

	void play();
	Player *winner();
	string score();
	const vector<Player *> getPlayers();

	~Game();
};

#endif	// __GAME_HPP__
