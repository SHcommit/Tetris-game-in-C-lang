#include "tetris_consoleCursor.h"
void GotoXY(int x, int y) { //Ŀ���� ���ϰ����ϴ� ��ǥ�� �̵�,
    COORD Pos;
    Pos.X = x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

COORD getCursor(void) { //���� Ŀ�� ��ġ�� ��ȯ
    COORD Pos;
    CONSOLE_SCREEN_BUFFER_INFO curInfo;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
    Pos.X = curInfo.dwCursorPosition.X;
    Pos.Y = curInfo.dwCursorPosition.Y;
    return Pos;
}

void CursorView(boolean show) {
    CONSOLE_CURSOR_INFO ConsoleCursor;
    ConsoleCursor.bVisible = show;
    ConsoleCursor.dwSize = 10;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConsoleCursor);
}