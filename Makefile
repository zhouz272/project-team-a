SRC = src/objPos.cpp src/objPosArrayList.cpp src/Food.cpp src/Player.cpp src/Game.cpp
TEST_SRC = test/objPosArrayListTest.cpp test/FoodTest.cpp test/PlayerTest.cpp
OBJ = $(SRC:.cpp=.o) $(TEST_SRC:.cpp=.o)

CXX = g++
CXXFLAGS = -Wall -g

EXEC = test_objPosArrayList test_Food test_Player game

all: $(EXEC)

test_objPosArrayList: src/objPos.o src/objPosArrayList.o test/objPosArrayListTest.o
	$(CXX) $(CXXFLAGS) -o $@ $^

test_Food: src/objPos.o src/objPosArrayList.o src/Food.o test/FoodTest.o
	$(CXX) $(CXXFLAGS) -o $@ $^

test_Player: src/objPos.o src/objPosArrayList.o src/Food.o src/Player.o test/PlayerTest.o
	$(CXX) $(CXXFLAGS) -o $@ $^

game: src/objPos.o src/objPosArrayList.o src/Food.o src/Player.o src/Game.o
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(OBJ) $(EXEC)
