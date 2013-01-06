#ifndef __UI_HPP__
#define __UI_HPP__

#include "Map.hpp"
#include "MapItem.hpp"
#include "Player.hpp"

class UI {
private:
	Map<MapItem> *map;
	void unit(Player *p, Unit *u);
	void building(Player *p, Building *b);

public:
	UI(Map<MapItem> *m) : map(m) {}
	void playerTurn(int turn, Player *p);
	bool eof();

	static void logAction(Unit *u, string action, string desc, pair<int, int> pos = { -1, -1 }, MapItem *tgt = NULL);
	static void logAction(Building *b, string action, string desc, MapItem *tgt = NULL);
};

#endif	// __UI_HPP__
