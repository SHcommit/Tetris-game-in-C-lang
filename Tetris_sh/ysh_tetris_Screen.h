#include "ysh_tetris_blocks.h"
#include "ysh_tetris_controller.h"
#pragma once

#ifndef Frame
#define Frame
int static level;
void InGameFrame();
void ShowNextBlock();
void DeleteNextBlock();
int static Rotation = 0;
void EndGameFrame();
void GameTitle();
void createBoards();
void addBlock(int shape, int rotate);
void deleteBlock();
int boards[Board_Height][Board_Width];
int NextBlock[6][6]; //nextshape
void printBoards();
void textcolor(int color_number);
typedef enum Color { DARKPURPLE = 5, GRAY = 8, BLUE = 9, GREEN = 10, AQUA = 11, RED = 12, PURPLE = 13, YELLOW = 14, WHITE = 15 }COLOR;
#endif