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

	Player(name, game)
	int getScore()
	int addScore(s)
	string getName()
	bool isAlive()

	const vector<Unit > getUnits()
	void addUnit(u)
	void delUnit(u)

	const vector<Building > getBuildings()
	void addBuilding(b)
	void delBuilding(b)

	int getGatherSpeed()

	const vector<Player > getEnemies()

	int getGold()
	int getWood()
	void addGold(quantity)
	void addWood(quantity)
	bool cost(gold, wood)
end



def Player(name, game)
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

def addUnit(u)
	@units.push_back(u)
end

def delUnit(u)
	@units.erase(find(@units.begin(), @units.end(), u))
end

const vector<Building >
def getBuildings()
	return @buildings
end

def addBuilding(b)
	@buildings.push_back(b)
end

def delBuilding(b)
	@buildings.erase(find(@buildings.begin(), @buildings.end(), b))
end

def getGold()
	return @gold
end

def getWood()
	return @wood
end

def addGold(quantity)
	@gold += quantity
end

def addWood(quantity)
	@wood += quantity
end

def cost(gold, wood)
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

def addScore(s)
	@score += s
	return @score
end

def getGatherSpeed()
	int gs = 10
	@buildings.each do |b|
		if (dynamic_cast<TownHall >(b))
			gs = max(gs, 40)
		if (dynamic_cast<Stronghold >(b))
			gs = max(gs, 50)
		if (dynamic_cast<Fortress >(b))
			gs = max(gs, 75)
	end
	return gs
end
