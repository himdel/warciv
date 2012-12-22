#include "Game.hpp"


Game::Game (int w, int h, std::string p1, std::string p2) {
	this->map = new Map<MapItem>(w, h)
	this->players = {
		new Player(p1),
		new Player(p2),
	};
	this->ui = new UI(this->map);
}

void
Game::play () {
}

Player *
Game::winner () {
}

string
Game::score () {
}

Game::~Game () {
}
