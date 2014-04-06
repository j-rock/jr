CC=g++
CFLAGS=-c -Wall
LDFLAGS=-lBox2D -lsfml-graphics -lsfml-window -lsfml-system
SOURCES=$(wildcard Game/*.cpp) $(wildcard Entity/*.cpp) $(wildcard Physics/*.cpp) $(wildcard Utils/*.cpp) $(wildcard Graphics/*.cpp)
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=out

all: $(EXECUTABLE) jr

jr:
	ar scrfv lib/libjr.a $(OBJECTS)
  
$(EXECUTABLE): $(OBJECTS) main.o
	$(CC) $(LDFLAGS) $(OBJECTS) main.o -o $@

sfmldemo:
	$(CC) $(LDFLAGS) Demos/circledemo.cpp -o $@

boxdemo:
	$(CC) $(LDFLAGS) Demos/boxdemo.cpp -o $@

mathdemo: 
	$(CC) Demos/mathdemo.cpp -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(EXECUTABLE) sfmldemo boxdemo mathdemo *.o Game/*.o Utils/*.o Physics/*.o Entity/*.o Demos/*.o Graphics/*.o lib/*
