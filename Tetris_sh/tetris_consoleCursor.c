#include "ysh_tetris_consoleCursor.h"

/**
* �ܼ�â���� Ŀ���� ���ϴ� ��ǥ�� �̵�.
* ���ڰ� x , y�� ��ġ�� Ŀ���� �̵��Ѵ�.
*/
void GotoXY(int x, int y) { //Ŀ���� ���ϰ����ϴ� ��ǥ�� �̵�,
    COORD Pos;
    Pos.X = x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}


/**
* getCursor( )
* �̶��� ��ȯ���� COORD �ڷ����� Pos�����ε�,
* COORD�� ���� ��ŷ�� ����. ������ x , y ���� ���� ����ü��.
* ���� Pos�� ��ȯ�� �ٴ� ���� GetStdHandle�� ���ؼ� �ܼ�â���� ��ġ�ϴ� Ŀ���� ��ǥ x, y�� ����ü Coord�� Pos�� ���� �����Ѵ�.
* �׸��� �ܼ�â���� ��µǰ� �ִ� ���� Ŀ�� ��ġ�� ��ȯ�Ѵ�.
*/
COORD getCursor(void) { //���� Ŀ�� ��ġ�� ��ȯ
    COORD Pos;
    CONSOLE_SCREEN_BUFFER_INFO curInfo;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
    Pos.X = curInfo.dwCursorPosition.X;
    Pos.Y = curInfo.dwCursorPosition.Y;
    return Pos;
}


/**
* CursorView(boolean show)
* ���ڰ��� ���� Ŀ���� �����̴°� ��������, ��������
* CursorInfo�� �����ִ� �Լ��̴�.
*/
void CursorView(boolean show) {
    CONSOLE_CURSOR_INFO ConsoleCursor;
    ConsoleCursor.bVisible = show;
    ConsoleCursor.dwSize = 10;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConsoleCursor);
}