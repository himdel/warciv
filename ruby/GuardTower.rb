# not ruby yet!

require './WatchTower.rb'

class GuardTower : public WatchTower {
public:
	GuardTower(Player *owner) : WatchTower("GuardTower", owner) {
		this->type = bt_GuardTower;
		this->hitpoints = 130;
		this->attack_range = 4;
		this->attack_damage = 4 + 12 * (rand() % 2);	# 4 + 12
		owner->addScore(20);
	}

	static Building *create(Player *owner) { return new GuardTower(owner); }
end

