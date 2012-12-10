#ifndef __MAPITEM_HPP__
#define __MAPITEM_HPP__

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

#endif	// __MAPITEM_HPP__
