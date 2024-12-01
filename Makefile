# Compiler and flags
CXX = g++
CXXFLAGS = -Iinclude -Wall -g

# Source files
SRC = src/objPos.cpp src/objPosArrayList.cpp
TEST_SRC = test/objPosArrayListTest.cpp
OBJ = $(SRC:.cpp=.o) $(TEST_SRC:.cpp=.o)

# Executable
EXEC = test_objPosArrayList

# Default rule to build the executable
all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)
