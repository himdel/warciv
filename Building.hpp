#ifndef __BUILDING_HPP__
#define __BUILDING_HPP__

#include <stdbool.h>
#include "enums.hpp"
#include "MapItem.hpp"
#include "Player.hpp"

class Building : public MapItem {
protected:
	Player *owner;
	int hitpoints;
	int feeds;
	BuildingType type;
	int range;
	int damage;

public:
	Building(std::string popis, Player *p) : MapItem(popis), owner(p) {
		this->type = bt_Any;
		this->hitpoints = 0;
		this->feeds = 0;
		this->range = 0;
		this->damage = 0;
	}

	virtual bool create(UnitType u);
	virtual void preturnAction() {}

	void damage(int hitpoints);

	virtual std::string getPopis();

	virtual bool upgrade();
};

#endif	// __BUILDING_HPP__
