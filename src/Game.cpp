#include <conio.h>    // for _kbhit() and _getch()
#include <windows.h>  //for Sleep()

#include <iostream>

#include "../include/Food.h"
#include "../include/Player.h"
#include "../include/objPosArrayList.h"

// Constants
constexpr int BOARD_WIDTH = 20;
constexpr int BOARD_HEIGHT = 10;
constexpr double MIN_SPEED = 0.01;
constexpr double MAX_SPEED = 0.50;

// Global Variables
Player player(BOARD_WIDTH / 2, BOARD_HEIGHT / 2, BOARD_WIDTH, BOARD_HEIGHT);
Food food;
double gameSpeed = MAX_SPEED;
bool exitFlag = false;

// Function Prototypes
void Initialize();
void GetInput();
void RunLogic();
void DrawScreen();
void LoopDelay();
void CleanUp();

int main(void) {
    Initialize();

    while (!exitFlag) {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();
    return 0;
}

void Initialize() {
    exitFlag = false;
    gameSpeed = MAX_SPEED;
    player = Player(BOARD_WIDTH / 2, BOARD_HEIGHT / 2, BOARD_WIDTH, BOARD_HEIGHT);
    food.generate(BOARD_WIDTH, BOARD_HEIGHT, player.getBody());
    std::cout << "Game Initialized. Let's play!" << std::endl;
}

void GetInput() {
    if (_kbhit()) {
        char key = _getch();
        switch (key) {
            case 'w':
                player.setDirection('U');
                break;
            case 'a':
                player.setDirection('L');
                break;
            case 's':
                player.setDirection('D');
                break;
            case 'd':
                player.setDirection('R');
                break;
            case '=':
                gameSpeed = std::max(MIN_SPEED, gameSpeed - 0.1);
                break;
            case '-':
                gameSpeed = std::min(MAX_SPEED, gameSpeed + 0.1);
                break;
            case 'q':
                exitFlag = true;
                break;  // Quit game
            default:
                break;
        }
    }
}

void RunLogic() {
    player.move();

    // Check collision with itself
    if (player.checkCollision()) {
        std::cout << "Game Over! You collided with yourself!" << std::endl;
        exitFlag = true;
        return;
    }

    // Check if player eats food
    if (player.eatsFood(food.getPosition())) {
        player.grow();
        food.generate(BOARD_WIDTH, BOARD_HEIGHT, player.getBody());
    }
}

void DrawScreen() {
    system("cls");

    // Top boundary
    for (int i = 0; i < BOARD_WIDTH + 2; ++i) std::cout << '#';
    std::cout << std::endl;

    // Game area
    for (int y = 0; y < BOARD_HEIGHT; ++y) {
        std::cout << '#';  // Left boundary
        for (int x = 0; x < BOARD_WIDTH; ++x) {
            if (player.getHead().getX() == x && player.getHead().getY() == y) {
                std::cout << '@';
            } else if (food.getPosition().getX() == x && food.getPosition().getY() == y) {
                std::cout << '*';
            } else if (player.isInBody(x, y)) {
                std::cout << '+';
            } else {
                std::cout << ' ';
            }
        }
        std::cout << '#' << std::endl;  // Right boundary
    }

    // Bottom boundary
    for (int i = 0; i < BOARD_WIDTH + 2; ++i) std::cout << '#';
    std::cout << std::endl;

    // Game information
    std::cout << "Current Game Speed: " << gameSpeed << " seconds." << std::endl;
    std::cout << "Press = to increase the Game Speed (up to 0.01 seconds)." << std::endl;
    std::cout << "Press - to decrease the Game Speed (down to 0.50 seconds)." << std::endl;
    std::cout << "Press 'w', 'a', 's', 'd' to move. Press 'q' to quit." << std::endl;
}

void LoopDelay() {
    Sleep(static_cast<DWORD>(gameSpeed * 1000));
}

void CleanUp() {
    std::cout << "Thanks for playing!" << std::endl;
}
