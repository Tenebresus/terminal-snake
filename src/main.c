#include <stdio.h>

#include "../include/numbers.h"
#include "../include/engine.h"
#include "../include/behaviour.h"

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

    while (1) {

        int pressedKey = getPressedkey();

        switch(pressedKey) {

            case 'w':
                snakeDirection = SNAKE_UP;
                break;

            case 's':
                snakeDirection = SNAKE_DOWN;
                break;

            case 'a':
                snakeDirection = SNAKE_LEFT;
                break;

            case 'd':
                snakeDirection = SNAKE_RIGHT;
                break;

            default:
                break;

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

        nextGameTick();

    }

    disableCanonMode();

    return 0;
}
