
CPP      = g++
CC       = gcc
OBJ      = main.o game.o birds.o physics.o  Animation.o worldbuilder.o levelreader.o
LINKOBJ  = main.o game.o birds.o physics.o  Animation.o worldbuilder.o levelreader.o
LIBS     = -L./Box2D-master/Box2D/lib -L/usr/include -L/usr/share/doc -L/usr/lib/x86_68-linux-gnu -static-libgcc /usr/lib/x86_64-linux-gnu/libsfml-audio.so /usr/lib/x86_64-linux-gnu/libsfml-graphics.so /usr/lib/x86_64-linux-gnu/libsfml-network.so /usr/lib/x86_64-linux-gnu/libsfml-system.so /usr/lib/x86_64-linux-gnu/libsfml-window.so ./Box2D-master/Box2D/Build/Box2D/libBox2D.a
CXXINCS	 = -I./Box2D-master/Box2D -I/usr/include
CXXFLAGS = $(CXXINCS) -std=c++11
BIN	 = angry


.PHONY: all all-before all-after clean clean-custom

# all: all-before $(BIN) all-after

$(BIN): $(OBJ)
	$(CPP) $(LINKOBJ) -o $(BIN) $(LIBS)

main.o: main.cpp
	$(CPP) -c main.cpp -o main.o $(CXXFLAGS)

game.o: game.cpp
	$(CPP) -c game.cpp -o game.o $(CXXFLAGS)

birds.o: birds.cpp
	$(CPP) -c birds.cpp -o birds.o $(CXXFLAGS)

physics.o: physics.cpp
	$(CPP) -c physics.cpp -o physics.o $(CXXFLAGS)

Animation.o: Animation.cpp
	$(CPP) -c Animation.cpp -o Animation.o $(CXXFLAGS)

worldbuilder.o: worldbuilder.cpp
	$(CPP) -c worldbuilder.cpp -o worldbuilder.o $(CXXFLAGS)

levelreader.o: levelreader.cpp
	$(CPP) -c levelreader.cpp -o levelreader.o $(CXXFLAGS)

