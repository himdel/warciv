# not ruby yet!

require './Unit.rb'

class Peon < Unit
private:
	bool cargo

public:
	Peon(Player owner) : Unit("Peon", owner) {
		@hitpoints = 30
		@cargo = false
		owner.addScore(30)
	}

	bool gather(int x, int y)
	bool build(int x, int y, BuildingType b)

	const set<ActionType> availActions() {
		return set<ActionType>({ at_None, at_Move, at_Build, at_Gather })
	}

	static Unit create(Player owner) { return Peon.new(owner); }
end

require './Peon.rb'
require './Resource.rb'
require './enums.rb'
require './buildings.rb'
require './TownHall.rb'
require './UI.rb'


# we don't unqueue gather, it loops by defualt
bool
Peon::gather(int x, int y) {
	# full, going to townhall
	if (@cargo) {
		# find closest TownHall or descendant
		auto f = [x, y] (MapItem mi, int px, int py) { return dynamic_cast<TownHall >(mi).nil? == false; }
		list< pair<int, int> > path = @map.closest(f, @x, @y)

		if (path.size() < 2) {
			UI::logAction(self, "gather", "unload cargo", make_pair(x, y))
			@cargo = false
			return true
		}

		return self.move(path.front().first, path.front().second)
	}

	if (self.distance(x, y) > 1)
		return self.move(x, y)

	# by the spot
	Resource spot = dynamic_cast<Resource >( @map.get(x, y) )
	if (!spot) {
		UI::logAction(self, "gather", "no resources", make_pair(x, y))
		return false
	}

	int gs = @owner.getGatherSpeed()
	int cargo = spot.gather(gs, @owner)
	@cargo = !! cargo

	@owner.addScore( (cargo % gs) ? 150 : cargo )

	ostringstream os
	os << "gathered " << cargo
	UI::logAction(self, "gather", os.str(), make_pair(x, y), spot)

	return @cargo
}

bool
Peon::build(int x, int y, BuildingType b) {
	bool r = self.move(x, y)
	if ((@x != x) || (@y != y))
		return r

	# on the spot
	MapItem mi = @map.get(x, y)
	if ((mi.nil? == false) && (mi != self)) {
		UI::logAction(self, "build", "not empty", make_pair(x, y), mi)
		return false
	}

	# actual build
	Building building = nil
	bool found = false

	for (unsigned i = 0; i < buildings_count; i++)
		if ((buildings[i].type == b) && (buildings[i].base == bt_Any)) {
			if (@owner.cost(buildings[i].gold, buildings[i].wood))
				building = buildings[i].make(@owner)
			found = true
			break
		}

	if (!found) {
		UI::logAction(self, "build", "can't build that here")
		return false
	}

	if (!building) {
		UI::logAction(self, "build", "not enough resources")
		return false
	}

	building.place(@map, @x, @y)
	@owner.addBuilding(building)

	# move unit to closest empty spot
	pair<int, int> empty = @map.closestEmpty(@x, @y)
	self.place(empty.first, empty.second)

	UI::logAction(self, "build", "built", make_pair(x, y), building)
	UI::logAction(self, "build", "unit moved", empty)

	if (@pending == at_Build)
		@pending = at_None

	return true
}
