#include <assert.h>
#include <cmath>
#include "MapItem.hpp"


static double
distance(int x1, int y1, int x2, int y2) {
	int dx = fabs(x1 - x2);
	int dy = fabs(y1 - y2);
	dx *= dx;
	dy *= dy;
	return sqrt(dx + dy);
}


MapItem::MapItem(std::string popis) {
	this->popis = popis;
	this->map = NULL;
}

void
MapItem::place(Map<MapItem> *map, int x, int y) {
	this->map = map;
	this->place(x, y);
}

void
MapItem::place(int x, int y) {
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

double
MapItem::distance(int x, int y) {
	return ::distance(this->x, this->y, x, y);
}

double
MapItem::distance(MapItem *i) {
	return ::distance(this->x, this->y, i->x, i->y);
}

std::ostream&
operator<<(std::ostream &o, MapItem *m) {
	return o << (m ? m->getPopis() : "(road)");
}
