#include "ysh_tetris_blocks.h"
#include "ysh_tetris_controller.h"
#include "ysh_tetris_Screen.h"
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")
int main(void) {
	CursorView(false);
	system("mode con cols=110 lines=35 | title tetris_¾ç½ÂÇö");
	//PlaySound(TEXT("Runaway.wav"), NULL, SND_ASYNC | SND_LOOP);

	GameTitle();
	tetris_process();
	InGameFrame();
	return 0;
}