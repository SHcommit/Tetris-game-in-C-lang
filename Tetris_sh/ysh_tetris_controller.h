#pragma once
#ifndef controller
#define controller

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#include <stdbool.h>
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ARROW 224
#define SPACEBAR 32
#define Board_Width 14
#define Board_Height 22
#define Blocks_SIZE 4
#define Blocks_Kinds 7
#define BlockStartX 14 
#define BlockStartY 4
#define BoardX 4
#define BoardY 3
bool IsMaxLine();
typedef enum gameSpeed { hard = 500, normal = 650, easy = 800 }SPEED;
int BlockCOL;
int BlockROW;//블록의 현재 좌표!!!
int curShape; //현재 모양
int nexShape; //다음 모양
int turn;
int nkey;
COORD Cursor; //테트리스 보드 내 현재 위치하는 커서
void tetris_process();
COORD getCursor(void); //현재 커서 좌표 반환 
void GotoXY(int x, int y);
void CursorView(boolean show);
void BlockRotate(); //방향키 받을시 rotate 를통해 방향키 변경
void CurrentShape();
void NextShape();
void IsBlockDropped();
void deleteLine();
boolean IsMaxLine();
boolean IsOverHeight();
boolean IsCollision(int shape, int rotate);
//void addBlock(int Boards[][Board_Height],int currentBlocks[][Blocks_SIZE]);
#endif // !controller