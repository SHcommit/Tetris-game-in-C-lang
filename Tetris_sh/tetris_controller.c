#include "ysh_tetris_controller.h"
#include "ysh_tetris_Screen.h"
void GotoXY(int x, int y) { //커서를 원하고자하는 좌표로 이동,
    COORD Pos;
    Pos.X = x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
COORD getCursor(void) { //현재 커서 위치를 반환
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
void BlockRotate() {
    turn = ++turn;
    if (turn == 4)
        turn = turn % 4;
}
void CurrentShape() {
    curShape = nexShape;
}
void NextShape() {
    srand(time(NULL));
    nexShape = rand() % Blocks_Kinds;
}
boolean IsOverHeight() {
    for (int x = 1; x < Board_Width - 1; x++) {
        int count = 0;
        for (int y = 1; y < Board_Height - 2; y++) {
            if (boards[y][x] == 1 || boards[y][x] == 2)
                ++count;
            if (count >= 18)
                return true;
        }
    }
    return false;
}
boolean IsCollision(int shape, int rotate) {
    COORD Pos = getCursor();
    BlockROW = Pos.X / 2 - BoardX;
    BlockCOL = Pos.Y - BoardY;
    for (int y = 0; y < Blocks_SIZE; y++)
        for (int x = 0; x < Blocks_SIZE; x++) {
            if ((Blocks[BlockCOL + y][BlockROW + x] == 1) && (Blocks[shape][rotate][y][x] == 1))
                return true;
        }
    return false;
}
void deleteLine() {
    int count = 0; // count가 12가되면 한 라인 전부 찼다는 뜻,
    for (int y = Board_Height - 1; y > 0; y--) {
        for (int x = 1; x < Board_Width - 1; x++) {
            if (boards[y][x] == 1)
                ++count;
            if (count == 12) {
                x = 1;
                boards[y][x] = 0;
                for (y; y > 0; y--)
                    for (x; x < 13; x++)
                        boards[y][x] = boards[y - 1][x];
                count = 0;
                return;
            }

        }
        count = 0;
    }
}
void tetris_process() {
    CursorView(false);
    system("mode con cols=150 lines=40 | title tetris_양승현");
    createBoards();
    srand(time(NULL));
    turn = 0;           //
    NextShape();        //
    CurrentShape();     //
    Cursor.X = BlockStartX; //이거 4개 다 반복될수있는것들이니까, 같이. 구조체로 정리하자
    Cursor.Y = BlockStartY; //
    //curX = BlockStartX; //이거 4개 다 반복될수있는것들이니까, 같이. 구조체로 정리하자
    //curY = BlockStartY; //
    while (1) {
        //만약 블록이 땅에 닿았다면? currentshpae();이후 nexShape( ) ; 그리고 커서 를 BlockStartX, y로.,
        printBoards();
        //setCursor(curX, curY);  //Cursor에다가 그냥 현재 커서위치 저장하는함수,
        GotoXY(Cursor.X, Cursor.Y);
        addBlock(curShape, turn);
        Sleep(hard);
        deleteBlock();
        if (_kbhit()) {
            nkey = _getch();
            if (nkey == ARROW) {
                nkey = _getch();
                switch (nkey) {
                case UP:
                    if (!IsCollision(curShape, turn)) {
                        BlockRotate();
                        addBlock(curShape, turn);
                    }
                    else
                        break;
                    break;
                case LEFT:
                    break;
                case RIGHT:
                case DOWN:
                    break;
                }
            }
        }
        deleteBlock(curShape, turn);
        deleteLine();
        if (!IsCollision(curShape, turn))
            Cursor.Y += 1;
    }
}