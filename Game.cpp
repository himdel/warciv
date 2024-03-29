#include <cstdlib>
#include <sstream>
#include <time.h>
#include "Game.hpp"
#include "Rock.hpp"
#include "GoldMine.hpp"
#include "Forest.hpp"

using namespace std;


Game::Game(int w, int h, string p1, string p2, int win_score) {
	srand(time(NULL));
	this->win_score = win_score;
	this->turn = 0;

	this->map = new Map<MapItem>(w, h);
	this->ui = new UI(this->map);

	this->genMap(0.1, 0.2);

	this->players = {
		new Player(p1, this),
		new Player(p2, this),
	};
}

void
Game::genMap(double pRock, double pRes) {
	if (pRock + pRes >= 1) {
		cerr << "genMap: pRock + pRes >= 1" << endl;
		return;
	}

	for (int x = 0; x < this->map->getWidth(); x++)
		for (int y = 0; y < this->map->getHeight(); y++) {
			MapItem *mi = NULL;
			int r = rand() % 100000;

			if (r < pRock * 100000)
				mi = new Rock();

			if ((r >= pRock * 100000) && (r < ((pRock + pRes) * 100000)))
				mi = (r % 2) ? (MapItem *) new Forest() : (MapItem *) new GoldMine();

			if (mi)
				mi->place(this->map, x, y);
		}
}

void
Game::play() {
	while (this->winner() == NULL) {
		this->turn++;
		for (Player *p : this->players)
			this->ui->playerTurn(turn, p);
		if (this->ui->eof())
			break;
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

		bool survivor = true;
		for (Player *e : p->getEnemies())
			survivor &= !e->isAlive();

		if (survivor && !best)
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

const vector<Player *>
Game::getPlayers() {
	return this->players;
}

Game::~Game() {
	delete this->ui;
	for (Player *p : this->players)
		delete p;
	delete this->map;
}
