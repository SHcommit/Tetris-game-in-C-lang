#include "ysh_tetris_controller.h"
#include "ysh_tetris_Screen.h"
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
    int count = 0; // count�� 12���Ǹ� �� ���� ���� á�ٴ� ��,
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
    system("mode con cols=150 lines=40 | title tetris_�����");
    createBoards();
    srand(time(NULL));
    turn = 0;           //
    NextShape();        //
    CurrentShape();     //
    Cursor.X = BlockStartX; //�̰� 4�� �� �ݺ��ɼ��ִ°͵��̴ϱ�, ����. ����ü�� ��������
    Cursor.Y = BlockStartY; //
    //curX = BlockStartX; //�̰� 4�� �� �ݺ��ɼ��ִ°͵��̴ϱ�, ����. ����ü�� ��������
    //curY = BlockStartY; //
    while (1) {
        //���� ����� ���� ��Ҵٸ�? currentshpae();���� nexShape( ) ; �׸��� Ŀ�� �� BlockStartX, y��.,
        printBoards();
        //setCursor(curX, curY);  //Cursor���ٰ� �׳� ���� Ŀ����ġ �����ϴ��Լ�,
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