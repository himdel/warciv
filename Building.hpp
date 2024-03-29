#ifndef __BUILDING_HPP__
#define __BUILDING_HPP__

#include <stdbool.h>
#include "enums.hpp"
#include "AttackMapItem.hpp"
#include "Player.hpp"

class Building : public AttackMapItem {
protected:
	int feeds;
	BuildingType type;

public:
	Building(std::string popis, Player *p) : AttackMapItem(popis, p) {
		this->type = bt_Any;
		this->feeds = 0;
	}

	virtual bool create(UnitType u);
	virtual void preturnAction() {}

	void damage(int hitpoints);

	virtual std::string getPopis();
	virtual std::string getDetail();

	virtual bool upgrade(BuildingType b);

	virtual BuildingType getType();
};

#endif	// __BUILDING_HPP__
