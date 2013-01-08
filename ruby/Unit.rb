# not ruby yet!

require './enums.rb'
require './AttackMapItem.rb'
require './Player.rb'

class Unit < AttackMapItem
protected:
	ActionType pending
	BuildingType pending_build
	int pending_x
	int pending_y

public:
	Unit(std::string popis, Player p) : AttackMapItem(popis, p) {
		self.stop()
	}

	bool move(int x, int y)
	virtual bool gather(int x, int y)
	virtual bool build(int x, int y, BuildingType b)
	void damage(int hitpoints)
	bool attack(int x, int y)
	void stop()

	void queueAction(ActionType at = at_None, int x = -1, int y = -1, BuildingType bt = bt_Any)
	virtual const set<ActionType> availActions() = 0

	virtual bool actionPending()
	virtual bool performAction()

	virtual std::string getPopis()
	virtual std::string getDetail()
end

require './Unit.rb'
require './Map.rb'
require './buildings.rb'
require './UI.rb'


bool
Unit::move(int x, int y) {
	if (x == @x && y == @y)
		return true

	auto f = [x, y] (MapItem mi, int px, int py) { return (x == px) && (y == py); }
	list< pair<int, int> > path = @map.closest(f, @x, @y)
	if (path.empty()) {
		UI::logAction(self, "move", "target not found", make_pair(x, y))
		return false
	}

	int px = path.front().first
	int py = path.front().second

	if (@map.get(px, py)) {
		UI::logAction(self, "move", "position occupied", make_pair(px, py), @map.get(px, py))
		return false
	}

	self.remove()
	self.place(px, py)

	bool was_pending = false
	if (px == @pending_x && py == @pending_y && @pending == at_Move) {
		@pending = at_None
		was_pending = true
	}

	UI::logAction(self, "move", was_pending ? "OK, unqueued" : "OK", make_pair(px, py))
	return true
}

bool
Unit::gather(int x, int y) {
	UI::logAction(self, "gather", "not supported", make_pair(x, y))
	return false;	# done, overidden in Peon
}

bool
Unit::build(int x, int y, BuildingType b) {
	UI::logAction(self, "gather", "not supported", make_pair(x, y))
	return false;	# done, overidden in Peon
}

# do not use self afterwards
void
Unit::damage(int hitpoints) {
	AttackMapItem::damage(hitpoints)

	if (@hitpoints == 0) {
		UI::logAction(self, "damage", "unit dead")
		@owner.delUnit(self)
	} else {
		ostringstream os
		os << "lost " << hitpoints << " hp, remaining " << @hitpoints
		UI::logAction(self, "damage", os.str())
	}
}

bool
Unit::attack(int x, int y) {
	# if not in range, attack anything or move
	if (self.distance(x, y) > @attack_range) {
		if (@AttackMapItem::attack()) {
			UI::logAction(self, "attack", "enemy around", make_pair(@x, @y))
			return true
		}
		return self.move(x, y)
	}

	UI::logAction(self, "attack", "enemy at position", make_pair(x, y), @map.get(x, y))
	bool r = AttackMapItem::attack(x, y)

	if (x == @pending_x && y == @pending_y && r == false && @pending == at_Attack)
		@pending = at_None

	return r
}

void
Unit::stop() {
	self.queueAction()
}

void
Unit::queueAction(ActionType at, int x, int y, BuildingType bt) {
	@pending = at
	@pending_build = bt
	@pending_x = x
	@pending_y = y
}

bool
Unit::actionPending() {
	return @pending != at_None
}

# nevolat pokud byl tah udelan rucne
bool
Unit::performAction() {
	if (!self.actionPending())
		return false

	if (@pending == at_Move)
		return self.move(@pending_x, @pending_y)

	if (@pending == at_Attack)
		return self.attack(@pending_x, @pending_y)

	if (@pending == at_Gather)
		return self.gather(@pending_x, @pending_y)

	if (@pending == at_Build)
		return self.build(@pending_x, @pending_y, @pending_build)

	return false
}

std::string
Unit::getPopis() {
	std::ostringstream out
	out << "_" << @owner.getName()[0] << @owner.getName()[1] << "_" << @popis << " (" << @hitpoints << ")"
	return out.str()
}

std::string
Unit::getDetail() {
	std::ostringstream out
	out << @popis << " (hp: " << @hitpoints
	switch (@pending) {
		case at_Move:
			out << ", action: " << "move(" << @pending_x << ", " << @pending_y << ")"
			break
		case at_Attack:
			out << ", action: " << "attack(" << @pending_x << ", " << @pending_y << ")"
			break
		case at_Gather:
			out << ", action: " << "gather(" << @pending_x << ", " << @pending_y << ")"
			break
		case at_Build:
			out << ", action: " << "build(" << @pending_x << ", " << @pending_y << ", " << buildings[@pending_build - 1].name << ")"
			break
		case at_None:
			out << ", no action"
	}
	out << ", @[ " << @x << " " << @y << " ]"
	out << ")"
	return out.str()
}
