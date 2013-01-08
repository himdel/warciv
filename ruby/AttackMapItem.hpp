#ifndef __ATTACKMAPITEM_HPP__
#define __ATTACKMAPITEM_HPP__

#include "MapItem.hpp"
class Player;

class AttackMapItem : public MapItem {
protected:
	Player *owner;
	int hitpoints;
	int attack_damage;
	int attack_range;

public:
	AttackMapItem(std::string popis, Player *p) : MapItem(popis), owner(p) {
		this->hitpoints = 0;
		this->attack_damage = 0;
		this->attack_range = 0;
	}

	virtual void damage(int hitpoints);

	virtual bool attack();
	virtual bool attack(int x, int y);
	virtual bool attack(AttackMapItem *i);
};

#endif	// __ATTACKMAPITEM_HPP__
