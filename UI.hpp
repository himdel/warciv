#ifndef __UI_HPP__
#define __UI_HPP__

#include "Map.hpp"
#include "MapItem.hpp"
#include "Player.hpp"

class UI {
private:
	Map<MapItem> *map;
public:
	UI(Map<MapItem> *m) : map(m) {}
	void playerTurn(Player *p);
};

#endif	// __UI_HPP__
