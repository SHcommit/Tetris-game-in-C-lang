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
int BlockROW;//����� ���� ��ǥ!!!
int curShape; //���� ���
int nexShape; //���� ���
int turn;
int nkey;
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
boolean IsCollision(int shape, int rotate);
//void addBlock(int Boards[][Board_Height],int currentBlocks[][Blocks_SIZE]);
#endif // !controller