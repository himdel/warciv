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



Player::Player(string name, Game game) {
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
}

int
Player::getScore() {
	return @score
}

string
Player::getName() {
	if (self.nil?)
		return "(none)"
	return @name
}

const vector<Unit >
Player::getUnits() {
	return @units
}

void
Player::addUnit(Unit u) {
	@units.push_back(u)
}

void
Player::delUnit(Unit u) {
	@units.erase(std::find(@units.begin(), @units.end(), u))
}

const vector<Building >
Player::getBuildings() {
	return @buildings
}

void
Player::addBuilding(Building b) {
	@buildings.push_back(b)
}

void
Player::delBuilding(Building b) {
	@buildings.erase(std::find(@buildings.begin(), @buildings.end(), b))
}

int
Player::getGold() {
	return @gold
}

int
Player::getWood() {
	return @wood
}

void
Player::addGold(int quantity) {
	@gold += quantity
}

void
Player::addWood(int quantity) {
	@wood += quantity
}

bool
Player::cost(int gold, int wood) {
	if ((@gold < gold) || (@wood < wood))
		return false

	@gold -= gold
	@wood -= wood
	return true
}

const vector<Player >
Player::getEnemies() {
	vector<Player > enemies
	for (Player p : @game.getPlayers())
		if (p != self)
			enemies.push_back(p)
	return enemies
}

bool
Player::isAlive() {
	return @buildings.size() || @units.size()
}

int
Player::addScore(int s) {
	@score += s
	return @score
}

int
Player::getGatherSpeed() {
	int gs = 10
	for (Building b: @buildings) {
		if (dynamic_cast<TownHall >(b))
			gs = max(gs, 40)
		if (dynamic_cast<Stronghold >(b))
			gs = max(gs, 50)
		if (dynamic_cast<Fortress >(b))
			gs = max(gs, 75)
	}
	return gs
}
