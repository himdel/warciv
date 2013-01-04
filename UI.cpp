#include <cstdio>
#include <ctype.h>
#include "UI.hpp"

void
UI::unit(Player *p, Unit *u) {
}

void
UI::building(Player *p, Building *b) {
}

void
UI::playerTurn(int turn, Player *p) {
	printf("\n\nTah: %d\n", turn);

	printf("Hrac: %s\n", p->getName().c_str());
	printf("\n");

	this->map->show();
	printf("\n");

	const vector<Building *> buildings = p->getBuildings();
	if (buildings.size()) {
		printf("Available buildings:\n");
		int i = 0;
		for (Building *b : buildings)
			printf("%d. %s\n", ++i, b->getDetail().c_str());
		printf("\n");
	}

	const vector<Unit *> units = p->getUnits();
	if (units.size()) {
		printf("Available units:\n");
		int i = 0;
		for (Unit *b : units)
			printf("%d. %s\n", ++i, b->getDetail().c_str());
		printf("\n");
	}

	for (;;) {
		if (cin.eof())
			return;

		char c;
		printf("Actions: [u]nit, [b]uilding, [t]urn\n");
		printf("> ");
		cin >> c;
		c = toupper(c);

		unsigned u, b;

		switch (c) {
			case 'U':
				cin >> u;
				if (u < 1 || u > units.size()) {
					printf("unknown unit %d\n", u);
					break;
				}
				this->unit(p, units[u]);
				break;

			case 'B':
				cin >> b;
				if (b < 1 || b > buildings.size()) {
					printf("unknown building %d\n", b);
					break;
				}
				this->building(p, buildings[b]);
				break;

			case 'T':
				return;

			default:
				printf("unknown action %c\n", c);
		}
	}
}

bool
UI::eof() {
	return cin.eof();
}
