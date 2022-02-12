#include "ysh_tetris_blocks.h"
#include "ysh_tetris_controller.h"
#include "ysh_tetris_Screen.h"
#include "ysh_tetris_consoleCursor.h"

int main(void) {
	CursorView(false);
	system("mode con cols=110 lines=35 | title tetris_양승현");
	/*
	* 아래의 PlaySound 메서드는.wav 음악 파일을 재생시켜주는 함수입니다.
	* controller.h 헤더파일에 include한 mmsystem.h 헤더파일을 통해
	* .wav음악을 출력시키는데, 음악을 출력할 경우
	* 해당 경로를 ysh_tetris_controller.h 에 BGM의 경로를 문자열로 지정하면 됩니다.
	* 그후 아래 PlaySound주석 해제.
	*/
	//PlaySound(TEXT(BGM), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	Sleep(1000);
	GameTitle();
	tetris_process();

	return 0;
}
