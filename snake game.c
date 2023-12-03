#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

int i, j, height = 20, width = 20;
int gameover, score;
int x, y, fruitX, fruitY, flag;
int tailX[100], tailY[100];  // Added this line

// Function to generate the fruit
void setup() {
    gameover = 0;

    // Initialize the position of the snake
    x = height / 2;
    y = width / 2;
    label1:
    fruitX = rand() % 20;
    if (fruitX == 0)
        goto label1;
    label2:
    fruitY = rand() % 20;
    if (fruitY == 0)
        goto label2;
    score = 0;  // Initialize the score
}

// Function to draw the board
void draw() {
    system("cls");
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            if (i == 0 || i == width - 1 || j == 0 || j == height - 1) {
                printf("#");
            } else {
                if (i == x && j == y)
                    printf("0");
                else if (i == fruitX && j == fruitY)
                    printf("*");
                else
                    printf(" ");
            }
        }
        printf("\n");
    }
    printf("Score: %d", score);
    printf("\n");
    printf("Press X to quit the game");
}

// Function to take input
void input() {
    if (_kbhit()) {
        switch (_getch()) {
            case 'a':
                flag = 1;
                break;
            case 's':
                flag = 2;
                break;
            case 'd':
                flag = 3;
                break;
            case 'w':
                flag = 4;
                break;
            case 'x':
                gameover = 1;
                break;
        }
    }
}

// Function to move the snake
void algorithm() {
    Sleep(100);
    int i;
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (i = 1; i < score; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    switch (flag) {
        case 1:
            y--;
            break;
        case 2:
            x++;
            break;
        case 3:
            y++;
            break;
        case 4:
            x--;
            break;
        default:
            break;
    }
    if (x < 0 || x > height || y < 0 || y > width)
        gameover = 1;

    for (i = 0; i < score; i++) {
        if (tailX[i] == x && tailY[i] == y)
            gameover = 1;
    }
    if (x == fruitX && y == fruitY) {
    label3:
        fruitX = rand() % 20;
        if (fruitX == 0)
            goto label3;
    label4:
        fruitY = rand() % 20;
        if (fruitY == 0)
            goto label4;
        score += 10;
    }
}

int main() {
    int m, n;
    setup();
    while (!gameover) {
        draw();
        input();
        algorithm();
    }
    return 0;
}
