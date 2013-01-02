CXX=g++ -std=c++11 -Wall
LD=true

# warciv: Axethrower.o Building.o Forest.o Game.o GoldMine.o Grunt.o MapItem.o Peon.o Player.o Unit.o WatchTower.o main.o units.o buildings.o Resource.o UI.o
#	$(LD) -o $@ $^ $(LDFLAGS)

warciv: main.o units.o buildings.o Game.o Player.o MapItem.o UI.o Resource.o Forest.o GoldMine.o Unit.o Building.o WatchTower.o
	$(LD) -o $@ $^ $(LDFLAGS)

clean:
	rm -f *.o warciv
