#ifndef _SNAKE
#define _SNAKE

#include <stdio.h>

#endif

struct snakePosition {
    int x;
    int y;
};

void showCherry(int x, int y);

void showSnake(int snakeLength, struct snakePosition *snakePositions, int snakeSteps);

int snakeCrossedBorder(int snakeX, int snakeY, int x, int y);

int snakeCollided(int snakeX, int snakeY, struct snakePosition *snakePositions, int snakeLength, int snakeSteps);