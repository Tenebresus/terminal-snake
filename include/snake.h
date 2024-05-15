#ifndef _SNAKE
#define _SNAKE

#include <stdio.h>

#endif

void showCherry(int x, int y);

struct snakePosition {
    int x;
    int y;
};

void showSnake(int snakeLength, struct snakePosition *snakePositions, int snakeSteps);
