#include "../include/Food.h"

#include <cstdlib>  // For rand()
#include <ctime>    // For time()

#include "../include/objPosArrayList.h"  // Include this for objPosArrayList

// Constructor
Food::Food() : foodPosition(0, 0, '*'), foodSymbol('*') {
    // Seed random number generator
    std::srand(std::time(nullptr));
}

// Generate new food at a random position
void Food::generate(int boardWidth, int boardHeight, const objPosArrayList& snakeBody) {
    bool validPosition = false;

    while (!validPosition) {
        int randomX = std::rand() % boardWidth;
        int randomY = std::rand() % boardHeight;

        foodPosition.setPosition(randomX, randomY);

        // Check if the position overlaps with the snake
        validPosition = true;
        for (int i = 0; i < snakeBody.getSize(); ++i) {
            if (snakeBody.getElement(i).getX() == randomX &&
                snakeBody.getElement(i).getY() == randomY) {
                validPosition = false;
                break;
            }
        }
    }
}

// Get food position
objPos Food::getPosition() const {
    return foodPosition;
}

// Get food symbol
char Food::getSymbol() const {
    return foodSymbol;
}
