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
	BuildingType type;

public:
	Building(std::string popis, Player *p) : MapItem(popis), owner(p) { this->type = bt_Any; }

	virtual bool create(UnitType u);
	virtual void preturnAction() {}

	void damage(int hitpoints);

	virtual std::string getPopis();

	virtual bool upgrade();
};

#endif	// __BUILDING_HPP__
