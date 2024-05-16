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
        printf("0");

    }

}

int snakeCrossedBorder(int snakeX, int snakeY, int x, int y) {

    return snakeX >= x || snakeX <= 0 || snakeY >= y || snakeY <= 0;

}

int snakeCollided(int snakeX, int snakeY, struct snakePosition *snakePositions, int snakeLength, int snakeSteps) {

    for (int i = snakeSteps - 1; i > snakeSteps - snakeLength; i--) {

        struct snakePosition sp = snakePositions[i];
        int spX = sp.x;
        int spY = sp.y;

        if (snakeX == spX && snakeY == spY) {
            return 1;
        }

    }

    return 0;

}