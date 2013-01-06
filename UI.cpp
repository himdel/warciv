#include <cstdio>
#include <ctype.h>
#include <functional>
#include <vector>
#include "UI.hpp"
#include "actions.hpp"
#include "units.hpp"
#include "buildings.hpp"

template<typename T>
static T choice(std::string title, const vector<T> options, bool back, std::function<void(T)> fun = [] (T d) { cout << d.name; } ) {
	printf("%s\n", title.c_str());

	for (unsigned i = 0; i < options.size(); i++) {
		printf("%d. ", i + 1);
		fun(options[i]);
		printf("\n");
	}
	if (back)
		printf("0. back\n");

	unsigned i = 0;
	do {
		printf("> ");
		cin >> i;
		if (cin.eof())
			throw EOF;
		if (cin.fail()) {
			cin.clear();
			string s;
			cin >> s;
			// ignored
		}
	} while (i < (back ? 0 : 1) || i > options.size());

	if (i == 0)
		throw 0;
	return options[i - 1];
}

void
UI::unit(Player *p, Unit *u) {
	// doable actions
	vector<ActionData> acts;
	for (unsigned i = 0; i < actions_count; i++)
		if (u->availActions().count( actions[i].type ))
			acts.push_back( actions[i] );

	// buildable buildings
	vector<BuildingData> bld;
	for (unsigned i = 0; i < buildings_count; i++)
		if (buildings[i].base == bt_Any)
			bld.push_back( buildings[i] );

	// the loop
	for (;;) {
		printf("Selected unit: %s\n", u->getDetail().c_str());

		if (acts.size() == 0) {
			printf("(no available actions)\n");
			return;
		}
		ActionData a = choice("Actions:", acts, true);

		int x, y;
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
			std::function<void(BuildingData)> fun = [] (BuildingData d) {
				printf("%s (gold %d, wood %d)", d.name.c_str(), d.gold, d.wood);
			};
			BuildingData bd = choice("\nBuild what?", bld, false, fun);
			bt = bd.type;
		}

		printf("\naction: %s", a.name.c_str());
		if (a.type != at_None)
			printf("(%d, %d)", x, y);
		if (bt)
			printf(" - %s", buildings[bt - 1].name.c_str());
		printf("\n");

		u->queueAction(a.type, x, y, bt);
	}
}

void
UI::building(Player *p, Building *b) {
	// doable actions
	struct BuAcData {
		string name;
		int gold;
		int wood;
		std::function<bool(void)> code;
	};
	vector< BuAcData > acts;

	for (unsigned bb = 0; bb < buildings_count; bb++)
		if (buildings[bb].base == b->Building::getType())
			acts.push_back({ "Upgrade to " + buildings[bb].name, buildings[bb].gold, buildings[bb].wood, [b, bb] () {
				return b->upgrade( buildings[bb].type );
			}});

	for (unsigned uu = 0; uu < units_count; uu++)
		if (units[uu].where == b->getType())
			acts.push_back({ "Build " + units[uu].name, units[uu].gold, units[uu].wood, [b, uu] () {
				return b->create( units[uu].type );
			}});

	// the loop
	for (;;) {
		printf("Selected building: %s\n", b->getDetail().c_str());

		if (acts.size() == 0) {
			printf("(no available actions)\n");
			return;
		}

		std::function< void(BuAcData) > fun = [] (BuAcData d) {
			printf("%s (gold %d, wood %d)", d.name.c_str(), d.gold, d.wood);
		};
		BuAcData c = choice("Actions:", acts, true, fun);
		bool r = c.code();
		printf("%s: %s\n", r ? "OK": "didn't finish", c.name.c_str());
	}
}

void
UI::playerTurn(int turn, Player *p) {
	printf("\n\nTah: %d\n", turn);

	printf("Hrac: %s\n", p->getName().c_str());
	printf("\n");

	this->map->show();
	printf("\n");

	for (Building *b : p->getBuildings())
		b->preturnAction();

	printf("Gold: %d; Wood: %d\n", p->getGold(), p->getWood());

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
		for (Unit *u : units)
			printf("%d. %s\n", ++i, u->getDetail().c_str());
		printf("\n");
	}

	if (units.empty() && buildings.empty()) {
		printf("(no actions available)\n");
		return;
	}

	for (;;) {
		if (cin.eof())
			throw EOF;

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
				try {
					this->unit(p, units[u - 1]);
				} catch (int e) {
					if (e != 0)
						throw e;
				}
				break;

			case 'B':
				cin >> b;
				if (b < 1 || b > buildings.size()) {
					printf("unknown building %d\n", b);
					break;
				}
				try {
					this->building(p, buildings[b - 1]);
				} catch (int e) {
					if (e != 0)
						throw e;
				}
				break;

			case 'T':
				for (Unit *u : units)
					u->performAction();
				//TODO probably destroy dead units here
				return;

			case 'Q':
				throw EOF;

			default:
				printf("unknown action %c\n", c);
		}
	}
}

bool
UI::eof() {
	return cin.eof();
}

/*static*/ void
UI::logAction(Unit *u, string action, string desc, pair<int, int> pos, MapItem *tgt) {
	printf("unit %s: %s", u->getPopis().c_str(), action.c_str());
	if (pos.first >= 0 && pos.second >= 0)
		printf("(%d, %d)", pos.first, pos.second);
	if (tgt)
		printf(" = %s", tgt->getPopis().c_str());
	if (desc != "")
		printf(" %s", desc.c_str());
	printf("\n");
}

/*static*/ void
UI::logAction(Building *b, string action, string desc, MapItem *tgt) {
	printf("building %s: %s", b->getPopis().c_str(), action.c_str());
	if (tgt)
		printf(" = %s", tgt->getPopis().c_str());
	if (desc != "")
		printf(" %s", desc.c_str());
	printf("\n");
}
