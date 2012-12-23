CXX=g++ -std=c++11
LD=true

# warciv: Axethrower.o Barracks.o Building.o CannonTower.o Farm.o Forest.o Fortress.o Game.o GoldMine.o Grunt.o GuardTower.o Map.o MapItem.o Peon.o Player.o Stronghold.o TownHall.o Unit.o WatchTower.o main.o units.o buildings.o Resource.o UI.o
#	$(LD) -o $@ $^ $(LDFLAGS)

warciv: Map.o main.o units.o buildings.o Game.o Player.o MapItem.o UI.o Resource.o Forest.o GoldMine.o Unit.o
	$(LD) -o $@ $^ $(LDFLAGS)

clean:
	rm -f *.o warciv
