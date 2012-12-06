LD=g++

projekt: CivEngine.o HraciDeska.o HraciPole.o ObjektovaHraciDeska.o Pole.o main.o
	$(LD) -o $@ $^ $(LDFLAGS)

clean:
	rm -f *.o projekt
