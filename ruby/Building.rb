require './AttackMapItem.rb'
require './Player.rb'
require './Rock.rb'
require './UI.rb'
require './buildings.rb'
require './enums.rb'
require './units.rb'
# not ruby yet!


class Building < AttackMapItem
protected:
	int feeds
	BuildingType type

public:
	Building(std::string popis, Player p) : AttackMapItem(popis, p) {
		@type = bt_Any
		@feeds = 0
	end

	virtual bool create(UnitType u)
	virtual void preturnAction() {}

	void damage(int hitpoints)

	virtual std::string getPopis()
	virtual std::string getDetail()

	virtual bool upgrade(BuildingType b)

	virtual BuildingType getType()
end




bool
Building::upgrade(BuildingType b) {
	Building building = nil

	for (unsigned i = 0; i < buildings_count; i++)
		if ((buildings[i].base == @type) && (buildings[i].type = b)) {
			if (@owner.cost(buildings[i].gold, buildings[i].wood))
				building = buildings[i].make(@owner)
			break
		end

	if (!building)
		return false

	self.remove()
	@owner.delBuilding(self)

	building.place(@map, @x, @y)
	@owner.addBuilding(building)

	UI::logAction(self, "upgrade", "upgraded", building)

	return true
end

static bool
isa(BuildingType is, BuildingType base) {
	while (is != base) {
		if (is == bt_Any)
			return false

		for (unsigned i = 0; i < buildings_count; i++)
			if (is == buildings[i].type) {
				is = buildings[i].base
				break
			end
	end
	return true
end

bool
Building::create(UnitType u) {
	Unit unit = nil

	for (unsigned i = 0; i < units_count; i++)
		if ((units[i].type == u) && isa(@type, units[i].where)) {
			if (@owner.cost(units[i].gold, units[i].wood))
				unit = units[i].make(@owner)
			break
		end

	if (!unit)
		return false

	pair<int, int> empty = @map.closestEmpty(@x, @y)
	unit.place(@map, empty.first, empty.second)
	@owner.addUnit(unit)

	UI::logAction(self, "create", "unit", unit)
	return true
end

void
Building::damage(int hitpoints) {
	AttackMapItem::damage(hitpoints)

	if (@hitpoints == 0) {
		UI::logAction(self, "damage", "building dead")
		@owner.delBuilding(self)

		(Rock.new()).place(@map, @x, @y)
	} else {
		ostringstream os
		os << "lost " << hitpoints << " hp, remaining " << @hitpoints
		UI::logAction(self, "damage", os.str())
	end
end

BuildingType
Building::getType() {
	return @type
end

string
Building::getPopis() {
	ostringstream os
	os << "_" << @owner.getName()[0] << @owner.getName()[1] << "_"
	os << MapItem::getPopis() << "(" << @hitpoints << ")"
	return os.str()
end

string
Building::getDetail() {
	ostringstream os
	os << @popis << " (hp: " << @hitpoints << ")"
	return os.str()
end
