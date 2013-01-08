# not ruby yet!

require './WatchTower.rb'

class CannonTower < WatchTower
public:
	CannonTower(Player *owner) : WatchTower("CannonTower", owner) {
		this->type = bt_CannonTower;
		this->hitpoints = 160;
		this->attack_damage = 50;
		this->attack_range = 3;
		owner->addScore(20);
	}

	static Building *create(Player *owner) { return new CannonTower(owner); }
end

