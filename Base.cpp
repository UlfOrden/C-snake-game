#include <stdio.h>
#include <stdlib.h>

#define WIDTH 20
#define HEIGHT 10

int main() {
    char board[HEIGHT][WIDTH];

    // Fill board with empty space
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            board[y][x] = ' ';
        }
    }

    // Initial snake (length 3)
    int snake_x[100] = {5, 4, 3};
    int snake_y[100] = {5, 5, 5};
    int length = 3;

    // Place snake on board
    for (int i = 0; i < length; i++) {
        board[snake_y[i]][snake_x[i]] = (i == 0) ? 'O' : 'o';
    }

    // Draw top wall
    for (int i = 0; i < WIDTH + 2; i++) printf("#");
    printf("\n");

    // Draw board
    for (int y = 0; y < HEIGHT; y++) {
        printf("#");
        for (int x = 0; x < WIDTH; x++) {
            printf("%c", board[y][x]);
        }
        printf("#\n");
    }

    // Draw bottom wall
    for (int i = 0; i < WIDTH + 2; i++) printf("#");
    printf("\n");

return 0;
}
