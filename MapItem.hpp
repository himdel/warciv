#ifndef __MAPITEM_HPP__
#define __MAPITEM_HPP__

#include <ostream>
#include "Map.hpp"

class MapItem {
protected:
	Map<MapItem> *map;
	int x, y;
	std::string popis;

public:
	MapItem(std::string popis);
	void place(Map<MapItem> *map, int x, int y);
	void remove();

	virtual std::string getPopis();
	virtual ~MapItem(){}
};

std::ostream& operator<<(std::ostream &o, MapItem *m);

#endif	// __MAPITEM_HPP__
