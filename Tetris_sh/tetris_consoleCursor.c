#include "ysh_tetris_consoleCursor.h"

/**
* 콘솔창에서 커서를 원하는 좌표로 이동.
* 인자값 x , y의 위치로 커서가 이동한다.
*/
void GotoXY(int x, int y) { //커서를 원하고자하는 좌표로 이동,
    COORD Pos;
    Pos.X = x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}


/**
* getCursor( )
* 이때의 반환값은 COORD 자료형의 Pos변수인데,
* COORD의 정의 피킹을 보면. 정수형 x , y 값을 갖는 구조체다.
* 따라서 Pos를 반환한 다는 것은 GetStdHandle을 통해서 콘솔창에서 위치하는 커서의 좌표 x, y를 구조체 Coord인 Pos에 값을 저장한다.
* 그리고 콘솔창에서 출력되고 있는 현재 커서 위치를 반환한다.
*/
COORD getCursor(void) { //현재 커서 위치를 반환
    COORD Pos;
    CONSOLE_SCREEN_BUFFER_INFO curInfo;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
    Pos.X = curInfo.dwCursorPosition.X;
    Pos.Y = curInfo.dwCursorPosition.Y;
    return Pos;
}


/**
* CursorView(boolean show)
* 인자값에 따라서 커서가 깜빡이는게 보여질지, 숨겨질지
* CursorInfo를 정해주는 함수이다.
*/
void CursorView(boolean show) {
    CONSOLE_CURSOR_INFO ConsoleCursor;
    ConsoleCursor.bVisible = show;
    ConsoleCursor.dwSize = 10;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConsoleCursor);
}