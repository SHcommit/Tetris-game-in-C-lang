#pragma once
#ifndef controller
#define controller

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#include <stdbool.h>

/**
* ���ӿ� ��µ� ���� ������ϰ� �����Դϴ�.
* BGM�� ������� "C:\\Users\\Desktop\\tetris\\���Ǹ�"
* ��θ� ���ڿ��� �����ؾ��մϴ�.
* #define���� BGM ���� �ϰ� main�Լ����� ��� ����.
* �ٵ� ���۱� ������ �ּ�ó��.
*/
#include<mmsystem.h>
#pragma comment(lib, "winmm.lib")
//��δ� \ ���ƴ϶� \\�� �ؾ���.
//#define BGM "C:\\Users\\SH\\Desktop\\Tetris_ysh_����_�ٸ���_�ڵ帮��_\\Runaway.wav"


/**
* ���� ����, ���� ����
* �ܼ�â���� ��µ� ���� ��� X, Y��ǥ
*/
enum boardProperty {
	BoardWidth = 14,
	BoardHeight = 22,
	BoardX = 4,
	BoardY = 3
};

enum Keys {
	LEFT = 75,
	RIGHT = 77,
	UP = 72,
	DOWN = 80,
	ARROW = 224,
	SPACEBAR = 32
};

typedef enum gameSpeed {
	easy = 230,
	normal = 170,
	hard = 150
}SPEED;

/**
* ����� ũ��
* ����� ȸ��
* ����� ����
* ����� Ŀ��â���� ���۵� x, y ��ǥ
*/
enum blockProperty {
	BlockSIZE = 4,
	BlockRotate = 4,
	BlockType = 7,
	BlockStartX = 14,
	BlockStartY = 4
};

// ����ڰ� �Է��� Ư�� ����Ű �ƽ�Ű �ڵ尪
int nkey;


/**
* ���� ������ �ܼ�â���� ��µǴ� 'Ŀ��'�� � ��ǥ�� �ش��ϴ��� �ľ��ϴ°� �߿��մϴ�.
* ���� ������ �ڵ忡�� Ư�� �׷����ϴ�.
* ���� ��ġ�� �ܼ־� Ŀ�� ��ǥ Cursor���� �� ��������
* ���� ����� ��� " curShape " ������ �ܼ�â�� ����� �� �ֱ� �����Դϴ�.
*
* prevBlockCOL , prevBlockROW�� ���� ����� ��ĭ �Ʒ��� ��������,
* ������ ��µ� ����� ��ġ�� �ش��ϴ� ����� ��� �̹����� ���־� �մϴ�.
*
* ���� �ٷ� ���� ��ǥ���� ���� �� ĭ�� ������ ������, ���ο� ���� ��ǥ����, ���Ű� �ǹ��� ���� ��ǥ���� ����� �մϴ�.
* �Ǵ� ���� �ܼ�â�� Ŀ�� ��ǥ�� Cursor�� �������� ���� �ȿ� �ִ� ���� ��ǥ���� ������
*	����ȿ� �����ϴ� ���� 14, ���� 22 �ȿ� ��µ� Ư���� 4*4ũ���� ù��° x,y index�� �����ϴ� ����Դϴ�.
****�ٽ� ���ؼ�
*		2���� �迭�� Board[22][14]�ȿ� ǥ�õ� ��� 4*4 ũ���� ù��° index , �ι�° index�� ���ϸ�
*		���� ����� ����Ҽ���, ������ ���� �ֽ��ϴ�.
*		���� �ܼ�â�� Ŀ���� ���ؼ� ������ ���� ù��° index�� Ư�� �������� �� ���ε�,
*		* �� �������� ù��° index�� BlockCOL�� �����߽��ϴ�.
*		* �������� �ι�° index = BlockROW
*		**
*		*���� Cursor������ ��ġ�� Ŀ���� ���� block�ȿ� ǥ�õǾ��� ����� ����, ���ΰ���
*		* prevBlockROW, prevBlockCOL�� �����߽��ϴ�.
* �� 4���� ������ Ȱ���� ����� ���� �ȿ��� ����� ����, ���� ���� �ִٴ� ���Դϴ�.
***
* ���ο� ���� ��ǥ���� ���� ��ĭ �Ʒ� ������ ���ο� ���� ��ǥ���� ����� ����ϴµ�,
* �� ������ ��µǾ��� ����� ���� index��(prevBlockROW&COL ����)�� ����
* ' 2 ' -> ' 0 '���� ������ �� �ֽ��ϴ�.
* ����� �ܼ�â���� �����ϴ� �Լ��� deletePrevBlock()
*
* �ܼ�â ������ �ٷ������ ��ǥ���� ũ�Ⱑ �������� short�� �����߽��ϴ�.
*/
//���� ��� ���
short curShape;
void CurrentShape();
//���� ��� ���
short nexShape;
void NextShape();
//����� ���� ��ǥ!!!
short BlockCOL;
short BlockROW;
//����� ���� ��ǥ
short prevBlockCOL;
short prevBlockROW;
//��Ʈ���� ���� �� ���� ��ġ�ϴ� Ŀ��
COORD Cursor;
//���� ��� �����
void deletePrevBlock();
//���ھ�
int static score;
void printScore();
//���� ���̵�
short gameLevel;
//���ο� ��� ���� ����
void newBlock();


/**
* ���ο� ����ΰ� ? (flag����.)
* ���ο� ��� == true�̶�� ���ο� ����� false ó�� �� �Ŀ�
* ShowNextBlock()�� ȣ���Ű�� ������ ���� ����� �� ���� ȭ��
* ��Ʈ���� ���� ���� �����ش�!
*/
boolean IsNextBlock;


/**
* ȸ�� ����� ����Ű�� �Է� ���� ��
* turn(���� ����� ȸ�� ���� 0,1,2,3�� ������� turn == 0��° ȸ�� ����(�ʱ���̶��)
* ' -> ' ����Ű�� ���� turn ==1�̵ǰ�, �̿� ����
* block���� ������
* block[Ư���� �� ���][0][][]����
* block[Ư���� �� ���][1][][]�� ȸ���� ����� ��µ� �� �ֵ��� turn�� ���¸�
* RotateBlock() �޼��带 ���� ��ȯ�Ѵ�.
*/
short turn;
void RotateBlock(); //����Ű ������ rotate ������ ����Ű ����


/**
* IsCollision(int shape, int rotate, int curX, int curY)
* ���� �ܼ�â�� Ŀ���� Cursor���� ��ĭ �������� ��
* �� ��ǥ���� �׷����� ����� ��Ʈ���� ������ �ٴڰ� ��ų�,
* bottom�� ����� ��� ������ ��ϰ� ��´ٸ�,
* true ��ȯ
* �׷� ��� ���� ��ǥ���� ������ �ٴڰ� ��ų�, �ٴ�ȭ?��(����ȭ��? �ٴڿ� ������) ����̶�� �ǴܵǱ⿡
* ���� ��ǥ�� ��µ� ����� ����� �ٴ����� �νĽ�ŵ�ϴ�. blockFixed(int shape, int rotate)
*/
boolean IsCollision(int shape, int rotate, int curX, int curY);
//����� bottom�� ����� ��� 
void blockFixed(int shape, int rotate);


/**
* ������ Ư�� �������� ������� ������ִ°�? IsMaxLine()
* yes? -> deleteLine()
*/
boolean IsMaxLine();
void deleteLine();
//ó�� ������ ����� õ��� ��Ҵ°�?
boolean IsOverHeight();


//�̸����� ��� ����� ���� �� �ش� ��ǥ �����ؾ��մϴ�.
COORD previewPoint;
//�̸����� ���, ���� ��� ���Ŀ� ���� ��� ȭ�鿡 ǥ��.
void previewBlock(int shape, int rotate);
//��Ʈ���� ���ư��µ� �־� ���� �߿��� �Լ�.(�����Լ����Դϴ�)
void tetris_process();
#endif // !controller