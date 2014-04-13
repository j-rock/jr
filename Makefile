CC=g++
CFLAGS=-c -Wall -g
LDFLAGS=-lBox2D -lsfml-graphics -lsfml-window -lsfml-system
SOURCES=$(wildcard Game/*.cpp) $(wildcard Entity/*.cpp) $(wildcard Physics/*.cpp) $(wildcard Utils/*.cpp) $(wildcard Graphics/*.cpp)
OBJECTS=$(SOURCES:.cpp=.o)

all: jr

jr: $(OBJECTS)
	ar scrfv lib/libjr.a $(OBJECTS)
  
sfmldemo:
	$(CC) $(LDFLAGS) Demos/circledemo.cpp -o $@

boxdemo:
	$(CC) $(LDFLAGS) Demos/boxdemo.cpp -o $@

mathdemo: 
	$(CC) Demos/mathdemo.cpp -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf sfmldemo boxdemo mathdemo *.o Game/*.o Utils/*.o Physics/*.o Entity/*.o Demos/*.o Graphics/*.o lib/*
