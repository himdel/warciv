require './Building.rb'
require './Fortress.rb'
require './Game.rb'
require './Peon.rb'
require './Stronghold.rb'
require './TownHall.rb'
require './Unit.rb'
# not ruby yet!




class Player
	vector<Unit > units
	vector<Building > buildings

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



def Player(string name, Game game)
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

def getScore()
	return @score
end

def getName()
	if (self.nil?)
		return "(none)"
	return @name
end

const vector<Unit >
def getUnits()
	return @units
end

def addUnit(Unit u)
	@units.push_back(u)
end

def delUnit(Unit u)
	@units.erase(find(@units.begin(), @units.end(), u))
end

const vector<Building >
def getBuildings()
	return @buildings
end

def addBuilding(Building b)
	@buildings.push_back(b)
end

def delBuilding(Building b)
	@buildings.erase(find(@buildings.begin(), @buildings.end(), b))
end

def getGold()
	return @gold
end

def getWood()
	return @wood
end

def addGold(int quantity)
	@gold += quantity
end

def addWood(int quantity)
	@wood += quantity
end

def cost(int gold, int wood)
	if ((@gold < gold) || (@wood < wood))
		return false

	@gold -= gold
	@wood -= wood
	return true
end

const vector<Player >
def getEnemies()
	vector<Player > enemies
	@game.getPlayers().each do |p|
		if (p != self)
			enemies.push_back(p)
	end
	return enemies
end

def isAlive()
	return @buildings.size() || @units.size()
end

def addScore(int s)
	@score += s
	return @score
end

def getGatherSpeed()
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
