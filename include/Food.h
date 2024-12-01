#ifndef FOOD_H
#define FOOD_H

#include "objPos.h"
#include "objPosArrayList.h"  // Include objPosArrayList here

class Food {
   private:
    objPos foodPosition;  // Position of the food
    char foodSymbol;      // Symbol to represent food (e.g., '*')

   public:
    // Constructor
    Food();

    // Generate new food at a random position
    // Updated method signature
    void generate(int boardWidth, int boardHeight, const objPosArrayList& snakeBody);

    // Get food position
    objPos getPosition() const;

    // Get food symbol
    char getSymbol() const;
};

#endif  // FOOD_H
