#pragma once
#ifndef controller
#define controller


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#include <stdbool.h>
//음악
#include<mmsystem.h>
#pragma comment(lib, "winmm.lib")

#define BGM "D:\\승현파일\\Tetris만듬\\tetris_sh\\Tetris_ysh\\Runaway.wav"
//별도로 헤더파일만들것
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
int static score;
boolean IsNextBLock;
int gameLevel;
typedef enum gameSpeed { easy = 230, normal = 170, hard = 150 }SPEED;
void addBlockColor();
void newBlock();
int BlockCOL;
int BlockROW;//블록의 현재 좌표!!!
int prevBlockCOL;
int prevBlockROW;
int curShape; //현재 모양
int nexShape; //다음 모양
int turn;
int nkey;
COORD previewPoint; //미리보기 븕럭만들고 지울 때 해당좌표 기억해주는 거
void printScore();
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
void blockFixed(int shape, int rotate);
boolean IsCollision(int shape, int rotate, int curX, int curY);
void colorRetention(int colorType);
void previewBlock(int shape, int rotate);
void prevAddBlockColor();
void deletePrevBlock();
#endif // !controller