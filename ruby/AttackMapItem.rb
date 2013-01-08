require './Building.rb'
require './MapItem.rb'
require './Unit.rb'
# not ruby yet!


class AttackMapItem < MapItem

	AttackMapItem(popis, p) : MapItem(popis), owner(p) {
		@hitpoints = 0
		@attack_damage = 0
		@attack_range = 0
	end

	virtual void damage(hitpoints)

	virtual bool attack()
	virtual bool attack(x, y)
	virtual bool attack(i)
end


def damage(hitpoints)
	@hitpoints -= min(@hitpoints, hitpoints)

	if (@hitpoints == 0)
		self.remove()
end


def attack()
	bool bb = false
	@owner.getEnemies().each do |e|
		e.getUnits().each do |u|
			if (self.distance(u) <= @attack_range)
				bb |= AttackMapItem::attack(u)
		end

		e.getBuildings().each do |b|
			if (self.distance(b) <= @attack_range)
				bb |= AttackMapItem::attack(b)
		end
	end
	return bb
end

def attack(x, y)
	MapItem i = @map.get(x, y)
	if (!i)
		return false

	AttackMapItem a = dynamic_cast<AttackMapItem >(i)
	if (!a)
		return false

	return self.attack(a)
end

# do not use i afterwards
def attack(i)
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
end
