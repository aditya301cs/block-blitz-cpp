#include "game.h"

void play() {
    while (1) {
        system("cls");
        drawBricks();
        drawBorder();

        // Draw slider
        gotoxy(sliderPos[1], sliderPos[0]);
        std::cout << "========";

        // Draw ball
        gotoxy(ballPos[1], ballPos[0]);
        std::cout << "O";

        if (_kbhit()) {
            char ch = _getch();
            if (ch == 'd' || ch == 'D' || ch == 77) {
                if (sliderPos[1] < 44) sliderPos[1] += 2;
            }
            if (ch == 'a' || ch == 'A' || ch == 75) {
                if (sliderPos[1] > 2) sliderPos[1] -= 2;
            }
            if (ch == ' ') startBall = 1;
            if (ch == 27) break; // ESC to quit
        }

        if (startBall) {
            // Move ball
            if (dir == 1) { // Top Right
                ballPos[0] -= 1;
                ballPos[1] += 2;
                if (ballPos[1] > MAXX) dir = 2;
                else if (ballPos[0] < MINY) dir = 4;
            }
            else if (dir == 2) { // Top Left
                ballPos[0] -= 1;
                ballPos[1] -= 2;
                if (ballPos[1] < MINX) dir = 1;
                else if (ballPos[0] < MINY) dir = 3;
            }
            else if (dir == 3) { // Bottom Left
                ballPos[0] += 1;
                ballPos[1] -= 2;
                if (ballPos[1] < MINX) dir = 4;
                else if (ballPos[0] > MAXY) { lose = 1; break; }
            }
            else if (dir == 4) { // Bottom Right
                ballPos[0] += 1;
                ballPos[1] += 2;
                if (ballPos[1] > MAXX) dir = 3;
                else if (ballPos[0] > MAXY) { lose = 1; break; }
            }
            ballHitSlider();
            ballHitBrick();
        }

        if (bricksLeft == 0) { win = 1; break; }

        Sleep(50);
    }

    system("cls");
    if (win) {
        gotoxy(20, 10);
        std::cout << "YOU WIN!";
    } else if (lose) {
        gotoxy(20, 10);
        std::cout << "YOU LOSE!";
    }
    gotoxy(18, 12);
    std::cout << "Press any key to return to menu...";
    getch();
}

void instructions() {
    system("cls");
    gotoxy(10, 5);
    std::cout << "Instructions:";
    gotoxy(10, 7);
    std::cout << "Use 'A' or Left Arrow to move left.";
    gotoxy(10, 8);
    std::cout << "Use 'D' or Right Arrow to move right.";
    gotoxy(10, 9);
    std::cout << "Press SPACE to launch the ball.";
    gotoxy(10, 11);
    std::cout << "Press any key to return to menu...";
    getch();
}