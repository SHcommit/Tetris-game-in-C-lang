#include "ysh_tetris_blocks.h"
#include "ysh_tetris_controller.h"
#include "ysh_tetris_Screen.h"
int main(void) {
	system("mode con cols=150 lines=40 | title tetris_양승현");
	//지금까지의 작업은 천장까지 고려한 구현이다. 하지만 블록이 딱 한개 바닥에 쌓이면 종료된다.
	tetris_process();

	return 0;
}