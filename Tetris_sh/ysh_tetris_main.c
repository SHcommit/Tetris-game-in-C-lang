#include "ysh_tetris_blocks.h"
#include "ysh_tetris_controller.h"
#include "ysh_tetris_Screen.h"
#include "ysh_tetris_consoleCursor.h"
int main(void) {
	CursorView(false);
	system("mode con cols=110 lines=35 | title tetris_�����");
	/*
	* �Ʒ��� PlaySound �޼����.wav ���� ������ ��������ִ� �Լ��Դϴ�.
	* controller.h ������Ͽ� include�� mmsystem.h ��������� ����
	* .wav������ ��½�Ű�µ�, ������ ����� ���
	* �ش� ��θ� ysh_tetris_controller.h �� BGM�� ��θ� ���ڿ��� �����ϸ� �˴ϴ�.
	* ���� �Ʒ� PlaySound�ּ� ����.
	*/
	//PlaySound(TEXT(BGM), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	Sleep(1000);
	GameTitle();
	tetris_process();

	return 0;
}