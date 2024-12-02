#include "../include/Food.h"

#include <cstdlib>  // for rand()
#include <ctime>    // for time()

// Constructor
Food::Food() : foodPosition(0, 0, '*'), foodSymbol('*') {
    std::srand(std::time(nullptr));  // Random number generator
}

// Generate a new random position for the food
void Food::generate(int boardWidth, int boardHeight, const objPosArrayList &snakeBody) {
    bool validPosition = false;

    while (!validPosition) {
        int randomX = std::rand() % boardWidth;
        int randomY = std::rand() % boardHeight;

        validPosition = true;
        for (int i = 0; i < snakeBody.getSize(); ++i) {
            if (snakeBody.getElement(i).getX() == randomX &&
                snakeBody.getElement(i).getY() == randomY) {
                validPosition = false;
                break;
            }
        }

        if (validPosition) {
            foodPosition.setPosition(randomX, randomY);  // Use setPosition to update position
        }
    }
}

// Get the food's position
objPos Food::getPosition() const {
    return foodPosition;
}

// Get the food's symbol
char Food::getSymbol() const {
    return foodSymbol;
}
