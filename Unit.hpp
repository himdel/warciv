#ifndef __UNIT_HPP__
#define __UNIT_HPP__

#include <stdbool.h>
#include "enums.hpp"
#include "MapItem.hpp"
#include "Player.hpp"

class Unit : public MapItem {
protected:
	Player *owner;
	int hp;

public:
	Unit(std::string popis, Player *p) : MapItem(popis), owner(p), hp(100) {}

	bool move(int x, int y);
	virtual bool gather(int x, int y);
	virtual bool build(int x, int y, BuildingType b);
	virtual bool attack(int x, int y);
	bool stop();
	void die();

	virtual bool actionPending();
	virtual bool performAction();

	virtual std::string getPopis();
};

#endif	// __UNIT_HPP__
