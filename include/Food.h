#ifndef FOOD_H
#define FOOD_H

#include "objPos.h"
#include "objPosArrayList.h"

class Food {
   private:
    objPos foodPosition;
    char foodSymbol;

   public:
    Food();
    void generate(int boardWidth, int boardHeight, const objPosArrayList &snakeBody);
    objPos getPosition() const;
    char getSymbol() const;
};

#endif