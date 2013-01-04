CXX=g++ -std=c++11 -Wall -g
LD=$(CXX)

warciv: main.o units.o buildings.o Game.o Player.o MapItem.o UI.o Resource.o Unit.o Building.o Peon.o AttackMapItem.o
	$(LD) -o $@ $^ $(LDFLAGS)

clean:
	rm -f *.o warciv core
