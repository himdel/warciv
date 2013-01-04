#ifndef __UNIT_HPP__
#define __UNIT_HPP__

#include <stdbool.h>
#include "enums.hpp"
#include "AttackMapItem.hpp"
#include "Player.hpp"

class Unit : public AttackMapItem {
public:
	Unit(std::string popis, Player *p) : AttackMapItem(popis, p) {}

	bool move(int x, int y);
	virtual bool gather(int x, int y);
	virtual bool build(int x, int y, BuildingType b);
	void damage(int hitpoints);
	bool attack(int x, int y);
	bool stop();
	void die();

	virtual bool actionPending();
	virtual bool performAction();

	virtual std::string getPopis();
};

#endif	// __UNIT_HPP__
