#include <iostream>

#include "../include/Food.h"
#include "../include/Player.h"

void testPlayer() {
    Player player(5, 5, 10, 10);  // Start at (5, 5) on a 10x10 board

    // Initial snake body
    std::cout << "Initial Snake Body:" << std::endl;
    for (int i = 0; i < player.getBody().getSize(); ++i) {
        player.getBody().getElement(i).print();
    }

    // Move the snake
    player.setDirection('U');
    player.move();
    std::cout << "After moving up:" << std::endl;
    for (int i = 0; i < player.getBody().getSize(); ++i) {
        player.getBody().getElement(i).print();
    }

    // Check collision with walls
    std::cout << "Collision with wall: " << (player.checkCollision() ? "Yes" : "No") << std::endl;

    // Grow the snake
    player.grow();
    std::cout << "After growing:" << std::endl;
    for (int i = 0; i < player.getBody().getSize(); ++i) {
        player.getBody().getElement(i).print();
    }
}

int main() {
    testPlayer();
    return 0;
}
