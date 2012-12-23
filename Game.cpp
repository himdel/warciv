#include <cstdlib>
#include <sstream>
#include <time.h>
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
	srand(time(NULL));
}

void
Game::play() {
	while (this->winner() == NULL) {
		this->turn++;
		for (Player *p : this->players)
			this->ui->playerTurn(turn, p);
	}
}

Player *
Game::winner() {
	Player *best = NULL;
	for (Player *p : this->players) {
		if (!best && (p->getScore() >= this->win_score))
			best = p;
		if (best && (p->getScore() >= best->getScore()))
			best = p;
	}
	return best;
}

string
Game::score() {
	ostringstream out;
	for (Player *p : this->players)
		out << p->getName() << "\t\t" << p->getScore() << endl;
	return out.str();
}


static void _delete_player(Player *p) {
	delete p;
}

Game::~Game() {
	delete this->ui;
	for (Player *p : this->players)
		delete p;
	delete this->map;
}
