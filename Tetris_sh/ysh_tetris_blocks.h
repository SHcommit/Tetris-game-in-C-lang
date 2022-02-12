/**
* tetris_blocks 파일
* 테트리스 블럭의 7가지 종류와, 각각의 블록이 회전할 수 있는 4가지 경우를 4차원 배열로 선언했습니다.
*/
#include "ysh_tetris_controller.h"
#pragma once
#ifndef BLOCKS
#define BLOCKS

int Blocks[BlockType][BlockRotate][BlockSIZE][BlockSIZE];
#endif // !Blocks