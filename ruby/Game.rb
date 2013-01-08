require './Forest.rb'
require './GoldMine.rb'
require './Map.rb'
require './MapItem.rb'
require './Player.rb'
require './Rock.rb'
require './UI.rb'
# not ruby yet!


class Game
	Map<MapItem> map
	vector<Player > players

	Game(w, h, p1, p2, win_score)
	void genMap(pRock, pRes)

	void play()
	Player winner()
	string score()
	const vector<Player > getPlayers()

	Map<MapItem> getMap() { return @map; }
end




def Game(w, h, p1, p2, win_score)
	srand(time(nil))
	@win_score = win_score
	@turn = 0

	@map = Map<MapItem>.new(w, h)
	@ui = UI.new(@map)

	self.genMap(0.1, 0.2)

	@players = {
		Player.new(p1, self),
		Player.new(p2, self),
	end
end

def genMap(pRock, pRes)
	if (pRock + pRes >= 1) {
		cerr << "genMap: pRock + pRes >= 1" << endl
		return
	end

	for (int x = 0; x < @map.getWidth(); x++)
		for (int y = 0; y < @map.getHeight(); y++) {
			MapItem mi = nil
			int r = rand() % 100000

			if (r < pRock * 100000)
				mi = Rock.new()

			if ((r >= pRock * 100000) && (r < ((pRock + pRes) * 100000)))
				mi = (r % 2) ? (MapItem ) Forest.new() : (MapItem ) GoldMine.new()

			if (mi)
				mi.place(@map, x, y)
		end
end

def play()
	while (self.winner().nil?) {
		@turn++
		@players.each do |p|
			@ui.playerTurn(turn, p)
		end
		if (@ui.eof())
			break
	end
end

Player *
def winner()
	Player best = nil
	@players.each do |p|
		if (!best && (p.getScore() >= @win_score))
			best = p
		if (best && (p.getScore() >= best.getScore()))
			best = p

		bool survivor = true
		p.getEnemies().each do |e|
			survivor &= !e.isAlive()
		end

		if (survivor && !best)
			best = p
	end
	return best
end

def score()
	@players.each do |p|
		out << p.getName() << "\t\t" << p.getScore() << endl
	end
	return out.str()
end

const vector<Player >
def getPlayers()
	return @players
end
