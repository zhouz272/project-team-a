SRC = src/objPos.cpp src/Food.cpp src/objPosArrayList.cpp
TEST_SRC = test/objPosArrayListTest.cpp test/FoodTest.cpp
OBJ = $(SRC:.cpp=.o) $(TEST_SRC:.cpp=.o)

EXEC = test_objPosArrayList test_Food

all: $(EXEC)

test_objPosArrayList: src/objPos.o src/objPosArrayList.o test/objPosArrayListTest.o
	$(CXX) $(CXXFLAGS) -o $@ $^

test_Food: src/objPos.o src/Food.o src/objPosArrayList.o test/FoodTest.o
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(OBJ) $(EXEC)
