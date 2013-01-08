require './Game.rb'
# not ruby yet!


main(int argc, char *argv) {
	Game g = Game.new(10, 10, "Karel", "Spock", 1000)

	cout << "3 .. 2 .. 1 .. Fight!" << endl
	g.play() rescue false

	cout << "Game over" << endl
	cout << "Winner: " << g.winner().getName() << endl
	cout << endl << "* Score *" << endl << g.score() << endl

	return 0
end
