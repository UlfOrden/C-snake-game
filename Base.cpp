#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 10

int main() {
    int game_over = 0;
    int score = 0;
    char dir = 'R';

    int snake_x[100] = {5, 4, 3};
    int snake_y[100] = {5, 5, 5};
    int length = 3;

    srand(time(NULL));
    int food_x = rand() % WIDTH;
    int food_y = rand() % HEIGHT;

    while (!game_over) {
        system("cls");

        // INPUT
        if (kbhit()) {
            char key = getch();
            if (key == 'w' && dir != 'D') dir = 'U';
            if (key == 's' && dir != 'U') dir = 'D';
            if (key == 'a' && dir != 'R') dir = 'L';
            if (key == 'd' && dir != 'L') dir = 'R';
        }

        // MOVE BODY
        for (int i = length - 1; i > 0; i--) {
            snake_x[i] = snake_x[i - 1];
            snake_y[i] = snake_y[i - 1];
        }

        // MOVE HEAD
        if (dir == 'U') snake_y[0]--;
        if (dir == 'D') snake_y[0]++;
        if (dir == 'L') snake_x[0]--;
        if (dir == 'R') snake_x[0]++;

        // WALL COLLISION
        if (snake_x[0] < 0 || snake_x[0] >= WIDTH ||
            snake_y[0] < 0 || snake_y[0] >= HEIGHT) {
            game_over = 1;
        }

        // SELF COLLISION
        for (int i = 1; i < length; i++) {
            if (snake_x[0] == snake_x[i] && snake_y[0] == snake_y[i]) {
                game_over = 1;
            }
        }

        // FOOD COLLISION
        if (snake_x[0] == food_x && snake_y[0] == food_y) {
            length++;
            score += 10;
            food_x = rand() % WIDTH;
            food_y = rand() % HEIGHT;
        }

        // SCORE
        printf("Score: %d\n", score);

        // TOP WALL
        for (int i = 0; i < WIDTH + 2; i++) printf("#");
        printf("\n");

        // BOARD
        for (int y = 0; y < HEIGHT; y++) {
            printf("#");
            for (int x = 0; x < WIDTH; x++) {
                int printed = 0;

                // Snake
                for (int i = 0; i < length; i++) {
                    if (snake_x[i] == x && snake_y[i] == y) {
                        printf(i == 0 ? "O" : "o");
                        printed = 1;
                        break;
                    }
                }

                // Food
                if (!printed && x == food_x && y == food_y) {
                    printf("*");
                    printed = 1;
                }

                if (!printed) printf(" ");
            }
            printf("#\n");
        }

        // BOTTOM WALL
        for (int i = 0; i < WIDTH + 2; i++) printf("#");
        printf("\n");

        Sleep(120);
    }

    system("cls");
    printf("GAME OVER\nFinal Score: %d\n", score);
    system("pause");
    return 0;
}
