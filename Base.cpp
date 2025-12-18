#include <stdio.h>
#include <stdlib.h>
#include <conio.h>   // for kbhit() and getch()
#include <windows.h> // for Sleep()

#define WIDTH 20
#define HEIGHT 10

int main() {
    int game_over = 0;
    char dir = 'R';

    int snake_x[100] = {5, 4, 3};
    int snake_y[100] = {5, 5, 5};
    int length = 3;

    while (!game_over) {
        system("cls");

        // INPUT (non-blocking)
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

        // DRAW TOP WALL
        for (int i = 0; i < WIDTH + 2; i++) printf("#");
        printf("\n");

        // DRAW BOARD
        for (int y = 0; y < HEIGHT; y++) {
            printf("#");
            for (int x = 0; x < WIDTH; x++) {
                int printed = 0;
                for (int i = 0; i < length; i++) {
                    if (snake_x[i] == x && snake_y[i] == y) {
                        printf(i == 0 ? "O" : "o");
                        printed = 1;
                        break;
                    }
                }
                if (!printed) printf(" ");
            }
            printf("#\n");
        }

        // DRAW BOTTOM WALL
        for (int i = 0; i < WIDTH + 2; i++) printf("#");
        printf("\n");

        Sleep(150);
    }

    system("cls");
    printf("GAME OVER\n");
    system("pause");
    return 0;
}
