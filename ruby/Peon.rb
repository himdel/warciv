# not ruby yet!

require './Unit.rb'

class Peon : public Unit {
private:
	bool cargo;

public:
	Peon(Player *owner) : Unit("Peon", owner) {
		this->hitpoints = 30;
		this->cargo = false;
		owner->addScore(30);
	}

	bool gather(int x, int y);
	bool build(int x, int y, BuildingType b);

	const set<ActionType> availActions() {
		return set<ActionType>({ at_None, at_Move, at_Build, at_Gather });
	}

	static Unit *create(Player *owner) { return new Peon(owner); }
};

require './Peon.rb'
require './Resource.rb'
require './enums.rb'
require './buildings.rb'
require './TownHall.rb'
require './UI.rb'


// we don't unqueue gather, it loops by defualt
bool
Peon::gather(int x, int y) {
	// full, going to townhall
	if (this->cargo) {
		// find closest TownHall or descendant
		auto f = [x, y] (MapItem *mi, int px, int py) { return dynamic_cast<TownHall *>(mi) != NULL; };
		list< pair<int, int> > path = this->map->closest(f, this->x, this->y);

		if (path.size() < 2) {
			UI::logAction(this, "gather", "unload cargo", make_pair(x, y));
			this->cargo = false;
			return true;
		}

		return this->move(path.front().first, path.front().second);
	}

	if (this->distance(x, y) > 1)
		return this->move(x, y);

	// by the spot
	Resource *spot = dynamic_cast<Resource *>( this->map->get(x, y) );
	if (!spot) {
		UI::logAction(this, "gather", "no resources", make_pair(x, y));
		return false;
	}

	int gs = this->owner->getGatherSpeed();
	int cargo = spot->gather(gs, this->owner);
	this->cargo = !! cargo;

	this->owner->addScore( (cargo % gs) ? 150 : cargo );

	ostringstream os;
	os << "gathered " << cargo;
	UI::logAction(this, "gather", os.str(), make_pair(x, y), spot);

	return this->cargo;
}

bool
Peon::build(int x, int y, BuildingType b) {
	bool r = this->move(x, y);
	if ((this->x != x) || (this->y != y))
		return r;

	// on the spot
	MapItem *mi = this->map->get(x, y);
	if ((mi != NULL) && (mi != this)) {
		UI::logAction(this, "build", "not empty", make_pair(x, y), mi);
		return false;
	}

	// actual build
	Building *building = NULL;
	bool found = false;

	for (unsigned i = 0; i < buildings_count; i++)
		if ((buildings[i].type == b) && (buildings[i].base == bt_Any)) {
			if (this->owner->cost(buildings[i].gold, buildings[i].wood))
				building = buildings[i].make(this->owner);
			found = true;
			break;
		}

	if (!found) {
		UI::logAction(this, "build", "can't build that here");
		return false;
	}

	if (!building) {
		UI::logAction(this, "build", "not enough resources");
		return false;
	}

	building->place(this->map, this->x, this->y);
	this->owner->addBuilding(building);

	// move unit to closest empty spot
	pair<int, int> empty = this->map->closestEmpty(this->x, this->y);
	this->place(empty.first, empty.second);

	UI::logAction(this, "build", "built", make_pair(x, y), building);
	UI::logAction(this, "build", "unit moved", empty);

	if (this->pending == at_Build)
		this->pending = at_None;

	return true;
}
