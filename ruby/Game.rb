# not ruby yet!

require './Map.rb'
require './MapItem.rb'
require './Player.rb'
require './UI.rb'

class Game
private:
	Map<MapItem> *map
	vector<Player *> players
	UI *ui
	int win_score
	int turn

public:
	Game(int w, int h, std::string p1, std::string p2, int win_score)
	void genMap(double pRock, double pRes)

	void play()
	Player *winner()
	string score()
	const vector<Player *> getPlayers()

	Map<MapItem> *getMap() { return @map; }

	~Game()
end

require './Game.rb'
require './Rock.rb'
require './GoldMine.rb'
require './Forest.rb'



Game::Game(int w, int h, string p1, string p2, int win_score) {
	srand(time(NULL))
	@win_score = win_score
	@turn = 0

	@map = new Map<MapItem>(w, h)
	@ui = new UI(@map)

	self.genMap(0.1, 0.2)

	@players = {
		new Player(p1, self),
		new Player(p2, self),
	}
}

void
Game::genMap(double pRock, double pRes) {
	if (pRock + pRes >= 1) {
		cerr << "genMap: pRock + pRes >= 1" << endl
		return
	}

	for (int x = 0; x < @map.getWidth(); x++)
		for (int y = 0; y < @map.getHeight(); y++) {
			MapItem *mi = NULL
			int r = rand() % 100000

			if (r < pRock * 100000)
				mi = new Rock()

			if ((r >= pRock * 100000) && (r < ((pRock + pRes) * 100000)))
				mi = (r % 2) ? (MapItem *) new Forest() : (MapItem *) new GoldMine()

			if (mi)
				mi.place(@map, x, y)
		}
}

void
Game::play() {
	while (self.winner() == NULL) {
		@turn++
		for (Player *p : @players)
			@ui.playerTurn(turn, p)
		if (@ui.eof())
			break
	}
}

Player *
Game::winner() {
	Player *best = NULL
	for (Player *p : @players) {
		if (!best && (p.getScore() >= @win_score))
			best = p
		if (best && (p.getScore() >= best.getScore()))
			best = p

		bool survivor = true
		for (Player *e : p.getEnemies())
			survivor &= !e.isAlive()

		if (survivor && !best)
			best = p
	}
	return best
}

string
Game::score() {
	ostringstream out
	for (Player *p : @players)
		out << p.getName() << "\t\t" << p.getScore() << endl
	return out.str()
}

const vector<Player *>
Game::getPlayers() {
	return @players
}

Game::~Game() {
	delete @ui
	for (Player *p : @players)
		delete p
	delete @map
}
