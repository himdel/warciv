# not ruby yet!

require './Building.rb'

class Barracks < Building
public:
	Barracks(Player *owner) : Building("Barracks", owner) {
		this->type = bt_Barracks;
		this->hitpoints = 800;
		owner->addScore(80);
	}

	static Building *create(Player *owner) { return new Barracks(owner); }
end

