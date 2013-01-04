#ifndef __ATTACKMAPITEM_HPP__
#define __ATTACKMAPITEM_HPP__

#include "MapItem.hpp"

class AttackMapItem : public MapItem {
protected:
	int hitpoints;
	int attack_damage;
	int attack_range;

public:
	AttackMapItem(std::string popis) : MapItem(popis) {
		this->hitpoints = 0;
		this->attack_damage = 0;
		this->attack_range = 0;
	}

	virtual void damage(int hitpoints);
	virtual bool attack(int x, int y);
};

#endif	// __ATTACKMAPITEM_HPP__
