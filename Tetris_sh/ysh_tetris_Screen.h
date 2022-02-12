#include "ysh_tetris_blocks.h"
#include "ysh_tetris_controller.h"

/**
* ������ ����, ������ ����Ǵ� ����ȭ�� �� �������ִ� �Լ���
* ���ǵǾ� �ֽ��ϴ�.
* ���� �ΰ��ӿ��� ���� �������� ��� ������ ����� ��µ� �����
* NextBlock 2���� �迭�� �����ϰ�, ����մϴ�.
*
*/
#pragma once

#ifndef Frame
#define Frame

typedef enum Color {
	DARKPURPLE = 5,
	GRAY = 8,
	BLUE = 9,
	GREEN = 10,
	AQUA = 11,
	RED = 12,
	PURPLE = 13,
	YELLOW = 14,
	WHITE = 15
}COLOR;

int static level;
//�ι�° ���� Scene
void InGameFrame();
// ���ӿ��� ��µ� ���� ��� �̸�����!
void ShowNextBlock();
// ���ӿ��� ��µ� ���� ��� �̸����� ����.
void DeleteNextBlock();
//�̸� ������ ����� �迭�� �����߽��ϴ�.
int NextBlock[6][6]; //nextshape
int static Rotation = 0;

void EndGameFrame();
void GameTitle();

/**
* tetris_controller.c �ҽ�����
* tetris_process()�޼��忡��
* ��Ʈ���� ���� �� ���� ����� ���<addBlock(shpae,rotate)>�ǰ�,
* ��ĭ �������� ���� ��µ� ����� ����<deleteBlock()> ��
* y�� ������ ���·� (������ ����) ���� ��� �ٽ� ���!<addBlock(shape,rotate)
* ����� ���, ���� �ϴ� �Լ��Դϴ�.
*/
void addBlock(int shape, int rotate);
void deleteBlock();

//���� ����. 0�� 1�� ����. 1 = ��, 0 = �� ����. �ڼ��ϰԴ� blockFixed()�޼��� �ּ� ����
void createBoards();
int board[BoardHeight][BoardWidth];
void printBoards();
//��Ͽ� �÷��� �ֱ� ���� textcolor����
void textcolor(int color_number);


#endif