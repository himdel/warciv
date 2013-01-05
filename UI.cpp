#include <cstdio>
#include <ctype.h>
#include <functional>
#include <vector>
#include "UI.hpp"
#include "actions.hpp"
#include "units.hpp"
#include "buildings.hpp"


void
UI::unit(Player *p, Unit *u) {
	// doable actions
	vector<ActionData> acts;
	int nacts = 0;
	for (unsigned i = 0; i < actions_count; i++)
		if (u->availActions().count( actions[i].type ))
			acts[nacts++] = actions[i];

	// buildable buildings
	vector<BuildingData> bld;
	int nbld = 0;
	for (unsigned i = 0; i < buildings_count; i++)
		if (buildings[i].base == bt_Any)
			bld[nbld++] = buildings[i];

	// the loop
	for (;;) {
		printf("Selected unit: %s\n", u->getDetail().c_str());

		printf("Actions:\n");
		for (int i = 0; i < nacts; i++)
			printf("%d. %s\n", i + 1, acts[i].name.c_str());
		printf("0. back");

		int i;
		printf("> ");
		cin >> i;
		if (i < 0 || i > nacts)
			continue;

		if (!i)
			break;

		int x, y;
		ActionData a = acts[i - 1];
		switch (a.type) {
			case at_None:
				x = y = -1;
				break;

			case at_Move:
			case at_Attack:
			case at_Gather:
			case at_Build:
				printf("target> ");
				cin >> x >> y;
				break;
		}

		BuildingType bt = bt_Any;
		if (a.type == at_Build) {
			printf("\nBuild what?\n");
			for (int i = 0; i < nbld; i++)
				printf("%d. %s\n", i + 1, bld[i].name.c_str());
			printf("0. back");

			int b;
			printf("> ");
			cin >> b;
			if ((b < 1) || (b > nbld))
				continue;

			bt = bld[b - 1].type;
		}

		printf("\naction: %s", a.name.c_str());
		if (a.type != at_None)
			printf("(%d, %d)", x, y);
		if (bt)
			printf(" - %s", buildings[bt].name.c_str());
		printf("\n");

		u->queueAction(a.type, x, y, bt);
	}
}

void
UI::building(Player *p, Building *b) {
	// doable actions
	struct BuAcData {
		string name;
		std::function<bool(void)> code;
	};
	vector< BuAcData > acts;
	int nacts = 0;

	for (unsigned bb = 0; bb < buildings_count; bb++)
		if (buildings[bb].base == b->Building::getType())
			acts[nacts++] = { "Upgrade to " + buildings[bb].name, [b, bb] () {
				return b->upgrade( buildings[bb].type );
			}};

	for (unsigned uu = 0; uu < units_count; uu++)
		if (units[uu].where == b->getType())
			acts[nacts++] = { "Build " + units[uu].name, [b, uu] () {
				return b->create( units[uu].type );
			}};

	// the loop
	for (;;) {
		printf("Selected building: %s\n", b->getDetail().c_str());

		printf("Actions:\n");
		for (int i = 0; i < nacts; i++)
			printf("%d. %s\n", i + 1, acts[i].name.c_str());
		printf("0. back");

		int i;
		printf("> ");
		cin >> i;
		if (i < 0 || i > nacts)
			continue;

		if (!i)
			break;

		bool r = acts[i - 1].code();
		printf("%s: %s\n", r ? "OK": "didn't finish", acts[i - 1].name.c_str());
	}
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
