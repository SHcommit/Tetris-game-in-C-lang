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
boolean IsCollision(int shape, int rotate, int curX, int curY) {
    BlockROW = curX / 2 - BoardX / 2; //이거는 x좌표여서 /2해야함
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
                    printf("■");
                }
        }
    }
    turn = 0;           //
    CurrentShape();     //
    NextShape();
    Cursor.X = BlockStartX; //이거 4개 다 반복될수있는것들이니까, 같이. 구조체로 정리하자
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
/*void deleteLine() {  //사라지긴하는데 한칸씩 안내려감
    COORD Pos = Cursor = getCursor();
    for (int y = Board_Height-2;y>0 ; y--) {
        int count = 0;// count가 12가되면 한 라인 전부 찼다는 뜻,
        for (int x = 1; x < Board_Width - 1; x++) {
            if (boards[y][x] == 1)
                ++count;
            if (count >= 12) {
                int height = y;
                for (int x = 1; x < Board_Width - 1; x++) {
                    boards[height][x] = 0;
                    GotoXY(x * 2 + BoardX, height + BoardY); //블럭 사라지는 모습 짜잔
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
void deleteLine() {  //사라지긴하는데 한칸씩 안내려감
    COORD Pos = Cursor = getCursor();
    for (int y = Board_Height - 2; y > 0; y--) {
        int count = 0;// count가 12가되면 한 라인 전부 찼다는 뜻,
        for (int x = 1; x < Board_Width - 1; x++) {
            if (boards[y][x] == 1)
                ++count;
            if (count >= 12) {
                int height = y;
                for (int x = 1; x < Board_Width - 1; x++) {
                    boards[height][x] = 0;
                    GotoXY(x * 2 + BoardX, height + BoardY); //블럭 사라지는 모습 짜잔
                    if (boards[height][x] == 0) {
                        printf("  "); Sleep(10);
                    }
                } //되는데 마지막칸ㅇ은작동이안되고 그위에부터되네?ㅋㅋ
                for (height; height > 0; height--) { //없앤 라인 기준이니까 한단계위에서부터 보드 유뮤 받아서 가는것!
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
                            printf("■");
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
    system("mode con cols=150 lines=40 | title tetris_양승현");
    createBoards();
    srand(time(NULL));
    turn = 0;           //
    NextShape();        //
    CurrentShape();     //
    NextShape();

    Cursor.X = BlockStartX; //이거 4개 다 반복될수있는것들이니까, 같이. 구조체로 정리하자
    Cursor.Y = BlockStartY; //
    while (1) {
        //만약 블록이 땅에 닿았다면? currentshpae();이후 nexShape( ) ; 그리고 커서 를 BlockStartX, y로.,
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
                case UP://버그 발견/... 회전할땨 벽붙어서회전하면 그대로박힘
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