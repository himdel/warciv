#include <cstdio>
#include <ctype.h>
#include "UI.hpp"
#include "actions.hpp"
#include "units.hpp"
#include "buildings.hpp"


void
UI::unit(Player *p, Unit *u) {
	// doable actions
	ActionData acts[actions_count];
	int nacts = 0;
	for (unsigned i = 0; i < actions_count; i++)
		if (u->availActions().count( actions[i].type ))
			acts[nacts++] = actions[i];

	// buildable buildings
	BuildingData bld[buildings_count];
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
	struct {
		string name,
		auto code,
	} acts[2];
	int nacts = 0;

	for (unsigned bb = 0; bb < buildings_count; bi++)
		if (buildings[bb].base == b->type)
			acts[nacts++] = { "Upgrade to " + buildings[bb].name, [b, bb] () {
				b->upgrade( buildings[bb].type );
			}};

	BuildingType btype = b->type;
	if (dynamic_cast<TownHall *>(b) != NULL)
		btype = bt_TownHall;
	for (unsigned uu = 0; uu < units_count; uu++)
		if (units[uu].where == btype)
			acts[nacts++] = { "Build " + units[uu].name, [b, uu] () {
				b->create( units[uu].type );
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

		printf("OK: %s done\n", acts[i - 1].name.c_str());
		acts[i - 1].code();
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
