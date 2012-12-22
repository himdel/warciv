#include <assert.h>
#include "MapItem.hpp"


MapItem::MapItem(std::string popis) {
	this->popis = popis;
	this->map = NULL;
}

void
MapItem::place(Map<MapItem> *map, int x, int y) {
	this->map = map;
	this->x = x;
	this->y = y;
	this->map->put(x, y, this);
}

void
MapItem::remove() {
	assert(this->map);
	assert(this->map->get(x, y) == this);
	this->map->put(x, y, NULL);
}

std::string
MapItem::getPopis() {
	return this->popis;
}
