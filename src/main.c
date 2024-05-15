#include <stdio.h>

#include "../include/numbers.h"
#include "../include/engine.h"
#include "../include/behaviour.h"
#include "../include/snake.h"

const int SNAKE_UP = 0;
const int SNAKE_DOWN = 1;
const int SNAKE_LEFT = 2;
const int SNAKE_RIGHT = 3;

int main() {

    initializeEngine();

    int dimensions[2];
    getScreenDimensions(dimensions);
    int x = dimensions[0];
    int y = dimensions[1];

    int snakeX = x / 2;
    int snakeY = y / 2; 

    int snakeDirection = SNAKE_UP;
    int snakeLength = 0;

    int snakeSteps = 0;
    struct snakePosition snakePositions[2048];

    int cherryX = rand() % x;
    int cherryY = rand() % y;

    while (1) {

        struct snakePosition snakePos;
        snakePos.x = snakeX;
        snakePos.y = snakeY;

        snakePositions[snakeSteps] = snakePos;

        showCherry(cherryX, cherryY);
        showSnake(snakeLength, snakePositions, snakeSteps);

        if (snakeX == cherryX && snakeY == cherryY) {
            snakeLength++;
            cherryX = rand() % x;
            cherryY = rand() % y;
        }

        int pressedKey = getPressedkey();

        if (pressedKey == 'w' && snakeDirection != SNAKE_DOWN) {
            snakeDirection = SNAKE_UP;
        }
        else if (pressedKey == 's' && snakeDirection != SNAKE_UP) {
            snakeDirection = SNAKE_DOWN;
        }
        else if (pressedKey == 'a' && snakeDirection != SNAKE_RIGHT) {
            snakeDirection = SNAKE_LEFT;
        }
        else if (pressedKey == 'd' && snakeDirection != SNAKE_LEFT) {
            snakeDirection = SNAKE_RIGHT;
        }

        switch(snakeDirection) {
            case SNAKE_UP:
                snakeY--;
                break;

            case SNAKE_DOWN:
                snakeY++;
                break;

            case SNAKE_LEFT:
                snakeX--;
                break;

            case SNAKE_RIGHT:
                snakeX++;
                break;
        }

        movePosition(snakeX, snakeY);
        snakeSteps++;

        nextGameTick();

    }

    disableCanonMode();

    return 0;
}
