#include <algorithm>
#include <sstream>
#include "Game.hpp"

using namespace std;


Game::Game(int w, int h, string p1, string p2, int win_score) {
	this->map = new Map<MapItem>(w, h);
	this->players = {
		new Player(p1),
		new Player(p2),
	};
	this->ui = new UI(this->map);
	this->win_score = win_score;
	this->turn = 0;
}

void
Game::play() {
	while (this->winner() == NULL) {
		this->turn++;
		for (vector<Player *>::iterator it = this->players.begin(); it != this->players.end(); it++)
			this->ui->playerTurn(turn, *it);
	}
}

Player *
Game::winner() {
	Player *best = NULL;
	for (vector<Player *>::iterator it = this->players.begin(); it != this->players.end(); it++) {
		if (!best && ((*it)->getScore() >= this->win_score))
			best = *it;
		if (best && ((*it)->getScore() >= best->getScore()))
			best = *it;
	}
	return best;
}

string
Game::score() {
	ostringstream out;
	for (vector<Player *>::iterator it = this->players.begin(); it != this->players.end(); it++) {
		out << (*it)->getName() << "\t\t" << (*it)->getScore() << endl;
	}
	return out.str();
}


static void _delete_player(Player *p) {
	delete p;
}

Game::~Game() {
	delete this->ui;
	for_each (this->players.begin(), this->players.end(), _delete_player);
	delete this->map;
}
