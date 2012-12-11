#ifndef __MAPITEM_HPP__
#define __MAPITEM_HPP__

#include <ostream>

class MapItem {
protected:
	Map *map;
	int x, y;
	std::string popis;

public:
	MapItem(std::string popis);
	void place(Map *map, int x, int y);
	void remove();

	virtual string getPopis();
	virtual ~MapItem(){}
};

ostream& operator<<(ostream &o, MapItem *m);

#endif	// __MAPITEM_HPP__
