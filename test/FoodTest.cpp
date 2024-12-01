#include <iostream>

#include "../include/Food.h"
#include "../include/objPosArrayList.h"

void testFoodWithSnake() {
    Food food;

    // Board dimensions
    int boardWidth = 10;
    int boardHeight = 10;

    // Fake snake body
    objPosArrayList snakeBody;
    snakeBody.insertTail(objPos(3, 3, 'S'));
    snakeBody.insertTail(objPos(4, 4, 'S'));
    snakeBody.insertTail(objPos(5, 5, 'S'));

    // Generate food and ensure it doesn't overlap with the snake
    for (int i = 0; i < 5; ++i) {
        food.generate(boardWidth, boardHeight, snakeBody);
        objPos foodPos = food.getPosition();

        // Print food position and symbol
        std::cout << "Food generated at: (" << foodPos.getX() << ", " << foodPos.getY() << ")"
                  << " Symbol: " << food.getSymbol() << std::endl;

        // Check that food does not overlap with the snake
        for (int j = 0; j < snakeBody.getSize(); ++j) {
            if (foodPos.getX() == snakeBody.getElement(j).getX() &&
                foodPos.getY() == snakeBody.getElement(j).getY()) {
                std::cerr << "Error: Food overlaps with snake body!" << std::endl;
            }
        }
    }
}

int main() {
    testFoodWithSnake();
    return 0;
}
