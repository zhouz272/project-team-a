#include "../include/Player.h"

Player::Player(int startX, int startY, int boardW, int boardH)
    : direction('R'), boardWidth(boardW), boardHeight(boardH) {
    snakeBody.insertTail(objPos(startX, startY, '@'));  // initialize snake head with "@"
}

objPos Player::getHead() const {
    return snakeBody.getHeadElement();  // location of snack's head
}

bool Player::isInBody(int x, int y) const {
    for (int i = 0; i < snakeBody.getSize(); ++i) {
        if (snakeBody.getElement(i).getX() == x && snakeBody.getElement(i).getY() == y) {
            return true;
        }
    }
    return false;
}

char Player::getDirection() const {
    return direction;
}

objPosArrayList Player::getBody() const {
    return snakeBody;
}

void Player::setDirection(char newDirection) {
    direction = newDirection;
}

void Player::move() {
    objPos head = snakeBody.getHeadElement();

    switch (direction) {
        case 'U':
            head.setY(head.getY() - 1);
            break;  // up
        case 'D':
            head.setY(head.getY() + 1);
            break;  // down
        case 'L':
            head.setX(head.getX() - 1);
            break;  // left
        case 'R':
            head.setX(head.getX() + 1);
            break;  // right
    }

    // Wrap around logic
    if (head.getX() < 0) head.setX(boardWidth - 1);
    if (head.getX() >= boardWidth) head.setX(0);
    if (head.getY() < 0) head.setY(boardHeight - 1);
    if (head.getY() >= boardHeight) head.setY(0);

    snakeBody.insertHead(head);  // remove head
    snakeBody.removeTail();      // remove tail
}

bool Player::checkCollision() const {
    objPos head = getHead();
    for (int i = 1; i < snakeBody.getSize(); ++i) {
        if (snakeBody.getElement(i).getX() == head.getX() &&
            snakeBody.getElement(i).getY() == head.getY()) {
            return true;  // hit body
        }
    }
    return false;
}

void Player::grow() {
    objPos tail = snakeBody.getTailElement();
    snakeBody.insertTail(tail);  // add a tail
}

bool Player::eatsFood(const objPos &food) const {
    objPos head = getHead();
    return head.getX() == food.getX() && head.getY() == food.getY();
}
