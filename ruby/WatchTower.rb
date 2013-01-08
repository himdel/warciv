# not ruby yet!

require './Building.rb'

class WatchTower : public Building {
public:
	WatchTower(std::string popis, Player *owner) : Building(popis, owner) {}
	WatchTower(Player *owner) : Building("WatchTower", owner) {
		this->type = bt_WatchTower;
		this->hitpoints = 100;
		this->attack_range = 2;
		this->attack_damage = 1;
		owner->addScore(50);
	}

	void preturnAction() { this->attack(); }

	static Building *create(Player *owner) { return new WatchTower(owner); }
end

