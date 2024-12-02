#ifndef OBJPOS_H
#define OBJPOS_H

#include <iostream>

class objPos {
   private:
    int x;
    int y;
    char symbol;

   public:
    objPos();
    objPos(int x, int y, char symbol);

    int getX() const;
    int getY() const;
    char getSymbol() const;

    void setX(int newX);
    void setY(int newY);
    void setSymbol(char newSymbol);

    void setPosition(int newX, int newY);

    void print() const;
};

#endif