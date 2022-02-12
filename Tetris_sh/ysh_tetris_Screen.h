#include "ysh_tetris_blocks.h"
#include "ysh_tetris_controller.h"

/**
* 게임의 시작, 게임이 진행되는 게임화면 을 구현해주는 함수가
* 정의되어 있습니다.
* 또한 인게임에서 현재 내려오는 블록 이후의 블록이 출력될 블록을
* NextBlock 2차원 배열로 정의하고, 출력합니다.
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
//두번째 게임 Scene
void InGameFrame();
// 게임에서 출력될 다음 블록 미리보기!
void ShowNextBlock();
// 게임에서 출력될 다음 블록 미리보기 삭제.
void DeleteNextBlock();
//미리 보여질 블록을 배열로 정의했습니다.
int NextBlock[6][6]; //nextshape
int static Rotation = 0;

void EndGameFrame();
void GameTitle();

/**
* tetris_controller.c 소스파일
* tetris_process()메서드에서
* 테트리스 보드 안 현재 블록이 출력<addBlock(shpae,rotate)>되고,
* 한칸 내려가면 현재 출력된 블록을 삭제<deleteBlock()> 후
* y값 증가된 상태로 (내려간 상태) 현재 블록 다시 출력!<addBlock(shape,rotate)
* 블록을 출력, 삭제 하는 함수입니다.
*/
void addBlock(int shape, int rotate);
void deleteBlock();

//보드 생성. 0과 1로 구성. 1 = 벽, 0 = 빈 공간. 자세하게는 blockFixed()메서드 주석 참고
void createBoards();
int board[BoardHeight][BoardWidth];
void printBoards();
//블록에 컬러를 넣기 위해 textcolor정의
void textcolor(int color_number);


#endif