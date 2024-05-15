#include "../include/snake.h"

void showCherry(int x, int y) {

    printf("\033[%d;%dH", y, x);
    printf("O");

}

void showSnake(int snakeLength, struct snakePosition *snakePositions, int snakeSteps) {

    for (int i = snakeSteps; i > snakeSteps - snakeLength; i--) {

        struct snakePosition sp = snakePositions[i];
        int snakeX = sp.x;
        int snakeY = sp.y;

        printf("\033[%d;%dH", snakeY, snakeX);
        printf("=");

    }

}