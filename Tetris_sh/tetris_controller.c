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
boolean IsCollision(int shape, int rotate, int curX, int curY) {
    BlockROW = curX / 2 - BoardX / 2; //�̰Ŵ� x��ǥ���� /2�ؾ���
    BlockCOL = curY - BoardY;
    for (int y = 0; y < Blocks_SIZE; y++) {
        for (int x = 0; x < Blocks_SIZE; x++) {
            if (Blocks[shape][rotate][y][x] == 2) {
                if (boards[BlockCOL + y][BlockROW + x] == 1) {
                    return true;
                }
            }
        }
    }
    return false;
}
void blockFixed(int shape, int rotate) {
    COORD Pos = getCursor();
    BlockROW = Pos.X / 2 - BoardX / 2;
    BlockCOL = Pos.Y - BoardY;
    for (int y = 0; y < Blocks_SIZE; y++) {
        for (int x = 0; x < Blocks_SIZE; x++) {
            if ((Blocks[shape][rotate][y][x] == 2))
                if (boards[BlockCOL + y][BlockROW + x] == 2) {
                    boards[BlockCOL + y][BlockROW + x] = 1;
                    GotoXY(Pos.X + x * 2, Pos.Y + y);
                    printf("��");
                }
        }
    }
    turn = 0;           //
    CurrentShape();     //
    NextShape();
    Cursor.X = BlockStartX; //�̰� 4�� �� �ݺ��ɼ��ִ°͵��̴ϱ�, ����. ����ü�� ��������
    Cursor.Y = BlockStartY;
    GotoXY(Cursor.X, Cursor.Y);
    addBlock(curShape, turn);
    deleteBlock();
}
boolean IsMaxLine() {
    for (int y = Board_Height - 2; y > 1; y--) {
        int count = 0;
        for (int x = 1; x < Board_Width - 1; x++) {
            if (boards[y][x] == 1)
                ++count;
            if (count >= 12)
                return true;
        }
    }
    return false;
}
/*void deleteLine() {  //��������ϴµ� ��ĭ�� �ȳ�����
    COORD Pos = Cursor = getCursor();
    for (int y = Board_Height-2;y>0 ; y--) {
        int count = 0;// count�� 12���Ǹ� �� ���� ���� á�ٴ� ��,
        for (int x = 1; x < Board_Width - 1; x++) {
            if (boards[y][x] == 1)
                ++count;
            if (count >= 12) {
                int height = y;
                for (int x = 1; x < Board_Width - 1; x++) {
                    boards[height][x] = 0;
                    GotoXY(x * 2 + BoardX, height + BoardY); //�� ������� ��� ¥��
                    printf("  "); Sleep(10);
                }
                for (height; height > 1; height--) {
                    for (int x = 1; x < Board_Width - 1; x++) {
                        boards[height][x]= boards[height - 1][x];
                    }
                    return;
                }
            }
        }
    }
    GotoXY(Cursor.X, Cursor.Y);
}*/
void deleteLine() {  //��������ϴµ� ��ĭ�� �ȳ�����
    COORD Pos = Cursor = getCursor();
    for (int y = Board_Height - 2; y > 0; y--) {
        int count = 0;// count�� 12���Ǹ� �� ���� ���� á�ٴ� ��,
        for (int x = 1; x < Board_Width - 1; x++) {
            if (boards[y][x] == 1)
                ++count;
            if (count >= 12) {
                int height = y;
                for (int x = 1; x < Board_Width - 1; x++) {
                    boards[height][x] = 0;
                    GotoXY(x * 2 + BoardX, height + BoardY); //�� ������� ��� ¥��
                    if (boards[height][x] == 0) {
                        printf("  "); Sleep(10);
                    }
                } //�Ǵµ� ������ĭ�����۵��̾ȵǰ� ���������͵ǳ�?����
                for (height; height > 0; height--) { //���� ���� �����̴ϱ� �Ѵܰ����������� ���� ���� �޾Ƽ� ���°�!
                    for (int x = 1; x < Board_Width - 1; x++) {
                        boards[height][x] = boards[height - 1][x];
                        if (boards[height - 1][x] == 0 || boards[height - 1][x] == 1) {
                            GotoXY(x * 2 + BoardX, height + BoardY);
                            printf("  ");
                        }
                    }
                }
                height = y;
                for (height; height > 0; height--) {
                    for (int x = 1; x < Board_Width - 1; x++) {
                        if (boards[height][x] == 1) {
                            GotoXY(x * 2 + BoardX, height + BoardY);
                            printf("��");
                        }
                        else {
                            GotoXY(x * 2 + BoardX, height + BoardY);
                            printf("  ");
                        }

                        if (height == 1)
                            boards[height][x] = 0;
                    }
                }
                GotoXY(Cursor.X, Cursor.Y);
                return;
            }
        }
    }
    GotoXY(Cursor.X, Cursor.Y);
}
void tetris_process() {
    CursorView(false);
    system("mode con cols=150 lines=40 | title tetris_�����");
    createBoards();
    srand(time(NULL));
    turn = 0;           //
    NextShape();        //
    CurrentShape();     //
    NextShape();

    Cursor.X = BlockStartX; //�̰� 4�� �� �ݺ��ɼ��ִ°͵��̴ϱ�, ����. ����ü�� ��������
    Cursor.Y = BlockStartY; //
    while (1) {
        //���� ����� ���� ��Ҵٸ�? currentshpae();���� nexShape( ) ; �׸��� Ŀ�� �� BlockStartX, y��.,
        printBoards();
        GotoXY(Cursor.X, Cursor.Y);
        addBlock(curShape, turn);
        if (_kbhit()) {
            nkey = _getch();
            if (nkey == SPACEBAR)
            {
                while (!IsCollision(curShape, turn, Cursor.X, Cursor.Y + 1))
                {
                    Sleep(15);
                    deleteBlock();
                    GotoXY(Cursor.X, Cursor.Y + 1);
                    addBlock(curShape, turn);
                    if (IsCollision(curShape, turn, Cursor.X, Cursor.Y + 1) == true)
                    {
                        blockFixed(curShape, turn);
                        break;
                    }
                }
                continue;
            }
            if (nkey == ARROW) {
                nkey = _getch();
                switch (nkey) {
                case UP://���� �߰�/... ȸ���ҋx ���پȸ���ϸ� �״�ι���
                    deleteBlock();
                    BlockRotate();
                    addBlock(curShape, turn);
                    break;
                case LEFT:
                    if (!IsCollision(curShape, turn, Cursor.X - 2, Cursor.Y)) {
                        deleteBlock();
                        GotoXY(Cursor.X - 2, Cursor.Y);
                        addBlock(curShape, turn);
                    }
                    else {
                        deleteBlock();
                        GotoXY(Cursor.X, Cursor.Y);
                        addBlock(curShape, turn);
                    }


                    break;
                case RIGHT:
                    if (!IsCollision(curShape, turn, Cursor.X + 2, Cursor.Y)) {
                        deleteBlock();
                        GotoXY(Cursor.X + 2, Cursor.Y);
                        addBlock(curShape, turn);
                    }

                    break;
                case DOWN:
                    if (!IsCollision(curShape, turn, Cursor.X, Cursor.Y + 1)) {
                        deleteBlock();
                        GotoXY(Cursor.X, Cursor.Y + 1);
                        addBlock(curShape, turn);
                    }
                    break;
                }
            }
        }
        Sleep(200);
        deleteBlock(curShape, turn);
        if (!IsCollision(curShape, turn, Cursor.X, Cursor.Y + 1))
            ++Cursor.Y;
        else {
            blockFixed(curShape, turn);
            if (IsMaxLine())
                deleteLine();
        }
        /*if (IsMaxLine())
            deleteLine();*/
    }
}