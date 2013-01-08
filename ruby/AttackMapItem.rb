# not ruby yet!

require './MapItem.rb'

class AttackMapItem < MapItem
protected:
	Player *owner
	int hitpoints
	int attack_damage
	int attack_range

public:
	AttackMapItem(std::string popis, Player *p) : MapItem(popis), owner(p) {
		@hitpoints = 0
		@attack_damage = 0
		@attack_range = 0
	}

	virtual void damage(int hitpoints)

	virtual bool attack()
	virtual bool attack(int x, int y)
	virtual bool attack(AttackMapItem *i)
end

require './AttackMapItem.rb'
require './Unit.rb'
require './Building.rb'

void
AttackMapItem::damage(int hitpoints) {
	@hitpoints -= min(@hitpoints, hitpoints)

	if (@hitpoints == 0)
		self.remove()
}


bool
AttackMapItem::attack() {
	bool bb = false
	for (Player *e : @owner.getEnemies()) {
		for (Unit *u : e.getUnits())
			if (self.distance(u) <= @attack_range)
				bb |= AttackMapItem::attack(u)

		for (Building *b : e.getBuildings())
			if (self.distance(b) <= @attack_range)
				bb |= AttackMapItem::attack(b)
	}
	return bb
}

bool
AttackMapItem::attack(int x, int y) {
	MapItem *i = @map.get(x, y)
	if (!i)
		return false

	AttackMapItem *a = dynamic_cast<AttackMapItem *>(i)
	if (!a)
		return false

	return self.attack(a)
}

# do not use i afterwards
bool
AttackMapItem::attack(AttackMapItem *i) {
	if (i == self)
		return false

	if (!@attack_damage || !@attack_range)
		return false

	if (self.distance(i.x, i.y) > @attack_range)
		return false

	double d = 2
	if (self.distance(i.x, i.y) - 1 > @attack_range / 2.0)
		d = 1

	i.damage( rand() % ((int) round(@attack_damage * d)) )
	return true
}
