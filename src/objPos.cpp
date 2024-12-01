#include "../include/objPos.h"

#include <iostream>

// Default Constructor
objPos::objPos() : x(0), y(0), symbol(' ') {}

// Parameterized Constructor
objPos::objPos(int x, int y, char symbol) : x(x), y(y), symbol(symbol) {}

// Destructor
objPos::~objPos() {}

// Getters
int objPos::getX() const { return x; }
int objPos::getY() const { return y; }
char objPos::getSymbol() const { return symbol; }

// Setters
void objPos::setPosition(int x, int y) {  // Implement this method
    this->x = x;
    this->y = y;
}

// Print Method
void objPos::print() const {
    std::cout << "Position: (" << x << ", " << y << ") Symbol: " << symbol << std::endl;
}
