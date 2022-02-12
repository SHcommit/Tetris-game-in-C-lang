#include "ysh_tetris_blocks.h"
#include "ysh_tetris_controller.h"
#pragma once

#ifndef Frame
#define Frame
int static Rotation = 0;
void createGameTitle();
void createBoards();
void addBlock(int shape, int rotate);
void deleteBlock();
int boards[Board_Height][Board_Width];
void printBoards();
void textcolor(int color_number);

#endif