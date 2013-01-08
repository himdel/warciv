require './Building.rb'
require './Fortress.rb'
require './Game.rb'
require './Peon.rb'
require './Stronghold.rb'
require './TownHall.rb'
require './Unit.rb'
# not ruby yet!




class Player
private:
	string name
	vector<Unit > units
	vector<Building > buildings
	int gold
	int wood
	int score
	Game game

public:
	Player(string name, Game game)
	int getScore()
	int addScore(int s)
	string getName()
	bool isAlive()

	const vector<Unit > getUnits()
	void addUnit(Unit u)
	void delUnit(Unit u)

	const vector<Building > getBuildings()
	void addBuilding(Building b)
	void delBuilding(Building b)

	int getGatherSpeed()

	const vector<Player > getEnemies()

	int getGold()
	int getWood()
	void addGold(int quantity)
	void addWood(int quantity)
	bool cost(int gold, int wood)
end



Player(string name, Game game) {
	@name = name
	@gold = 2400
	@wood = 1200
	@score = 0
	@game = game

	Unit peon = Peon.new(self)
	auto map = game.getMap()
	pair<int, int> empty = map.closestEmpty(rand() % map.getWidth(), rand() % map.getHeight())
	peon.place(map, empty.first, empty.second)
	self.addUnit(peon)
end

int
getScore() {
	return @score
end

string
getName() {
	if (self.nil?)
		return "(none)"
	return @name
end

const vector<Unit >
getUnits() {
	return @units
end

void
addUnit(Unit u) {
	@units.push_back(u)
end

void
delUnit(Unit u) {
	@units.erase(find(@units.begin(), @units.end(), u))
end

const vector<Building >
getBuildings() {
	return @buildings
end

void
addBuilding(Building b) {
	@buildings.push_back(b)
end

void
delBuilding(Building b) {
	@buildings.erase(find(@buildings.begin(), @buildings.end(), b))
end

int
getGold() {
	return @gold
end

int
getWood() {
	return @wood
end

void
addGold(int quantity) {
	@gold += quantity
end

void
addWood(int quantity) {
	@wood += quantity
end

bool
cost(int gold, int wood) {
	if ((@gold < gold) || (@wood < wood))
		return false

	@gold -= gold
	@wood -= wood
	return true
end

const vector<Player >
getEnemies() {
	vector<Player > enemies
	@game.getPlayers().each do |p|
		if (p != self)
			enemies.push_back(p)
	end
	return enemies
end

bool
isAlive() {
	return @buildings.size() || @units.size()
end

int
addScore(int s) {
	@score += s
	return @score
end

int
getGatherSpeed() {
	int gs = 10
	for (Building b: @buildings) {
		if (dynamic_cast<TownHall >(b))
			gs = max(gs, 40)
		if (dynamic_cast<Stronghold >(b))
			gs = max(gs, 50)
		if (dynamic_cast<Fortress >(b))
			gs = max(gs, 75)
	end
	return gs
end
