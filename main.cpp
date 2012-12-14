#include <iostream>
#include "Game.hpp"

using namespace std;

int
main(int argc, char **argv) {
	Game *g = new Game(10, 10, "Karel", "Spock");

	cout << "3 .. 2 .. 1 .. Fight!" << endl;
	g->play();

	cout << "Game over" << endl;
	cout << "Winner: " << g->winner()->getName() << endl;
	cout << endl << "Score" << endl << g->score() << endl;

	delete g;
	return 0;
}
