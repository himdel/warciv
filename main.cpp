#include <iostream>
#include "Game.hpp"

using namespace std;

int
main(int argc, char **argv) {
	Game *g = new Game(10, 10, "Karel", "Spock");

	delete g;
	return 0;
}
