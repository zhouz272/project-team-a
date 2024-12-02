#include "../include/objPos.h"

#include <iostream>

// Default Constructor
objPos::objPos() : x(0), y(0), symbol(' ') {}

// Parameterized Constructor
objPos::objPos(int x, int y, char symbol) : x(x), y(y), symbol(symbol) {}

// Getters
int objPos::getX() const {
    return x;
}

int objPos::getY() const {
    return y;
}

char objPos::getSymbol() const {
    return symbol;
}

// Setters
void objPos::setX(int newX) {
    x = newX;
}

void objPos::setY(int newY) {
    y = newY;
}

void objPos::setSymbol(char newSymbol) {
    symbol = newSymbol;
}

// New setPosition method
void objPos::setPosition(int newX, int newY) {
    x = newX;
    y = newY;
}

// Print function for debugging
void objPos::print() const {
    std::cout << "Position: (" << x << ", " << y << ") Symbol: " << symbol << std::endl;
}
