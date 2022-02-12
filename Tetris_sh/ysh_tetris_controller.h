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
int static score;
boolean IsNextBLock;
int gameLevel;
typedef enum gameSpeed { easy = 230, normal = 170, hard = 150 }SPEED;
void addBlockColor();
void newBlock();
int BlockCOL;
int BlockROW;//����� ���� ��ǥ!!!
int curShape; //���� ���
int nexShape; //���� ���
int turn;
int nkey;
void printScore();
COORD Cursor; //��Ʈ���� ���� �� ���� ��ġ�ϴ� Ŀ��
void tetris_process();
COORD getCursor(void); //���� Ŀ�� ��ǥ ��ȯ 
void GotoXY(int x, int y);
void CursorView(boolean show);
void BlockRotate(); //����Ű ������ rotate ������ ����Ű ����
void CurrentShape();
void NextShape();
void IsBlockDropped();
void deleteLine();
boolean IsMaxLine();
boolean IsOverHeight();
void blockFixed(int shape, int rotate);
boolean IsCollision(int shape, int rotate, int curX, int curY);
void colorRetention(int colorType);
#endif // !controller