#ifndef __UNIT_HPP__
#define __UNIT_HPP__

#include <stdbool.h>
#include "enums.hpp"
#include "AttackMapItem.hpp"
#include "Player.hpp"

class Unit : public AttackMapItem {
protected:
	ActionType pending;
	BuildingType pending_build;
	int pending_x;
	int pending_y;

public:
	Unit(std::string popis, Player *p) : AttackMapItem(popis, p) {
		this->stop();
	}

	bool move(int x, int y);
	virtual bool gather(int x, int y);
	virtual bool build(int x, int y, BuildingType b);
	void damage(int hitpoints);
	bool attack(int x, int y);
	void stop();

	void queueAction(ActionType at = at_None, int x = -1, int y = -1, BuildingType bt = bt_Any);

	virtual bool actionPending();
	virtual bool performAction();

	virtual std::string getPopis();
	virtual std::string getDetail();
};

#endif	// __UNIT_HPP__
