#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <conio.h>
#include <windows.h>

#define SCREEN_WIDTH 52
#define SCREEN_HEIGHT 20
#define MINX 2
#define MINY 2
#define MAXX 49
#define MAXY 19

// Function declarations
void gotoxy(int x, int y);
void drawBorder();
void drawBricks();
void ballHitSlider();
void ballHitBrick();
void play();
void instructions();
void initGame();

// Global variables declarations
extern HANDLE console;
extern COORD CursorPosition;
extern int bricks[24][2];
extern int visibleBricks[24];
extern int sliderPos[2];
extern int ballPos[2];
extern int startBall;
extern int dir;
extern int bricksLeft;
extern int win, lose;

#endif // GAME_H