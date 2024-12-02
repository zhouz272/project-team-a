#ifndef PLAYER_H
#define PLAYER_H

#include "objPos.h"
#include "objPosArrayList.h"

class Player {
   private:
    objPosArrayList snakeBody;
    char direction;
    int boardWidth;
    int boardHeight;

   public:
    Player(int startX, int startY, int boardW, int boardH);

    // Getters
    objPos getHead() const;             // Get head location
    bool isInBody(int x, int y) const;  // Check whether inside snake body
    char getDirection() const;
    objPosArrayList getBody() const;

    // Setters
    void setDirection(char newDirection);

    // Game logic
    void move();
    bool checkCollision() const;
    void grow();
    bool eatsFood(const objPos &food) const;
};

#endif  // PLAYER_H
