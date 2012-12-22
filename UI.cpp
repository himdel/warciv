#include <cstdio>
#include "UI.hpp"


void
UI::playerTurn(int turn, Player *p) {
	printf("\n\nTah: %d\n", turn);
	printf("Hrac: %s\n", p->getName().c_str());
	printf("\n");
	this->map->show();
	printf("\n");
	printf("Available actions:\n");
	printf("1. foo\n");
	printf("\n");
	getchar();
	//TODO
}
