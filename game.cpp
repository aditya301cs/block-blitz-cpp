#include "game.h"

// Global variables definitions
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

int bricks[24][2] = {
    {2,7},{2,12},{2,17},{2,22},{2,27},{2,32},
    {4,7},{4,12},{4,17},{4,22},{4,27},{4,32},
    {6,7},{6,12},{6,17},{6,22},{6,27},{6,32},
    {8,7},{8,12},{8,17},{8,22},{8,27},{8,32}
};

int visibleBricks[24] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
int sliderPos[2] = {18, 22};
int ballPos[2] = {17, 26};
int startBall = 0;
int dir = 1; // 1 - TopRight, 2 - TopLeft, 3 - BottomLeft, 4 - BottomRight
int bricksLeft = 24;
int win = 0, lose = 0;

void gotoxy(int x, int y) {
    CursorPosition.X = x;
    CursorPosition.Y = y;
    SetConsoleCursorPosition(console, CursorPosition);
}

void drawBorder() {
    gotoxy(0, 0);
    for (int i = 0; i <= SCREEN_WIDTH; i++) std::cout << "-";
    gotoxy(0, SCREEN_HEIGHT);
    for (int i = 0; i <= SCREEN_WIDTH; i++) std::cout << "-";

    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        gotoxy(0, i); std::cout << "|";
        gotoxy(SCREEN_WIDTH, i); std::cout << "|";
    }
}

void drawBricks() {
    for (int i = 0; i < 24; i++) {
        if (visibleBricks[i] == 1) {
            gotoxy(bricks[i][1], bricks[i][0]);
            std::cout << "####";
        }
    }
}

void ballHitSlider() {
    if (ballPos[1] >= sliderPos[1] && ballPos[1] <= sliderPos[1] + 8) {
        if (ballPos[0] == sliderPos[0] - 1) {
            if (dir == 3) dir = 2;
            else if (dir == 4) dir = 1;
        }
    }
}

void ballHitBrick() {
    for (int i = 0; i < 24; i++) {
        if (visibleBricks[i] == 1) {
            if (ballPos[1] >= bricks[i][1] && ballPos[1] <= bricks[i][1] + 4) {
                if (ballPos[0] == bricks[i][0]) {
                    visibleBricks[i] = 0;
                    bricksLeft--;
                    if (dir == 1) dir = 3;
                    else if (dir == 2) dir = 4;
                }
            }
        }
    }
}

void initGame() {
    sliderPos[0] = 18; sliderPos[1] = 22;
    ballPos[0] = 17; ballPos[1] = 26;
    startBall = 0; dir = 1; win = 0; lose = 0;
    bricksLeft = 24;
    for (int i = 0; i < 24; i++) visibleBricks[i] = 1;
}