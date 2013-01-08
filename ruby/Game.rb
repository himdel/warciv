require './Forest.rb'
require './GoldMine.rb'
require './Map.rb'
require './MapItem.rb'
require './Player.rb'
require './Rock.rb'
require './UI.rb'
# not ruby yet!


class Game
private:
	Map<MapItem> map
	vector<Player > players
	UI ui
	int win_score
	int turn

public:
	Game(int w, int h, string p1, string p2, int win_score)
	void genMap(double pRock, double pRes)

	void play()
	Player winner()
	string score()
	const vector<Player > getPlayers()

	Map<MapItem> getMap() { return @map; }
end




Game(int w, int h, string p1, string p2, int win_score) {
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

void
genMap(double pRock, double pRes) {
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

void
play() {
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
winner() {
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

string
score() {
	ostringstream out
	@players.each do |p|
		out << p.getName() << "\t\t" << p.getScore() << endl
	end
	return out.str()
end

const vector<Player >
getPlayers() {
	return @players
end
