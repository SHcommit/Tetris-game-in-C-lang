#include "ysh_tetris_blocks.h"
#include "ysh_tetris_controller.h"
#include "ysh_tetris_Screen.h"
int main(void) {
	system("mode con cols=150 lines=40 | title tetris_�����");
	//���ݱ����� �۾��� õ����� ����� �����̴�. ������ ����� �� �Ѱ� �ٴڿ� ���̸� ����ȴ�.
	tetris_process();

	return 0;
}