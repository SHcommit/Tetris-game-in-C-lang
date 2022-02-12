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
void printScore() {
    GotoXY(36, 20);
    printf("⊙ Score : %d", score);
}
/*void colorRetention(int colorType) { //deleteLine후 블록이 내려올때 위에있던 색 그대로 출력!
    switch (colorType) {
    case BLUE:
        textcolor(BLUE);
        printf("■");
        textcolor(WHITE);
        break;
    case GREEN:
        textcolor(GREEN);
        printf("■");
        textcolor(WHITE);
        break;
    case AQUA:
        textcolor(AQUA);
        printf("■");
        textcolor(WHITE);
        break;
    case RED:
        textcolor(RED);
        printf("■");
        textcolor(WHITE);
        break;
    case PURPLE:
        textcolor(PURPLE);
        printf("■");
        textcolor(WHITE);
        break;
    case YELLOW:
        textcolor(YELLOW);
        printf("■");
        textcolor(WHITE);
        break;
    case WHITE:
        textcolor(GRAY);
        printf("■");
        textcolor(WHITE);
        break;
    }
}*/
void colorRetention(int colorType) {
    switch (colorType) {
    case 0:
        textcolor(BLUE);
        printf("■");
        textcolor(WHITE);
        break;
    case 1:
        textcolor(GREEN);
        printf("■");
        textcolor(WHITE);
        break;
    case 2:
        textcolor(AQUA);
        printf("■");
        textcolor(WHITE);
        break;
    case 3:
        textcolor(RED);
        printf("■");
        textcolor(WHITE);
        break;
    case 4:
        textcolor(PURPLE);
        printf("■");
        textcolor(WHITE);
        break;
    case 5:
        textcolor(YELLOW);
        printf("■");
        textcolor(WHITE);
        break;
    case 6:
        textcolor(GRAY);
        printf("■");
        textcolor(WHITE);
        break;

    }
}

void addBlockColor() {
    switch (curShape) {
    case 0:
        textcolor(BLUE);
        printf("■");
        textcolor(WHITE);
        break;
    case 1:
        textcolor(GREEN);
        printf("■");
        textcolor(WHITE);
        break;
    case 2:
        textcolor(AQUA);
        printf("■");
        textcolor(WHITE);
        break;
    case 3:
        textcolor(RED);
        printf("■");
        textcolor(WHITE);
        break;
    case 4:
        textcolor(PURPLE);
        printf("■");
        textcolor(WHITE);
        break;
    case 5:
        textcolor(YELLOW);
        printf("■");
        textcolor(WHITE);
        break;
    case 6:
        textcolor(GRAY);
        printf("■");
        textcolor(WHITE);
        break;

    }
}
boolean IsOverHeight() {//또는 시작할때 4*4가 1이랑 2랑 같이 있으면 게임 오버
    BlockROW = BlockStartX / 2;
    BlockCOL = 1;
    for (int y = 0; y < Blocks_SIZE; y++) {
        for (int x = 0; x < Blocks_SIZE; x++) {
            if (boards[BlockCOL + y][BlockROW + x * 2] == 2 && boards[BlockCOL + y + 1][BlockROW + x * 2] >= 3)
                return true;
        }
    }
    return false;
}

boolean IsCollision(int shape, int rotate, int curX, int curY) {
    BlockROW = curX / 2 - BoardX / 2; //이거는 x좌표여서 /2해야함
    BlockCOL = curY - BoardY;
    for (int y = 0; y < Blocks_SIZE; y++) {
        for (int x = 0; x < Blocks_SIZE; x++) {
            if (Blocks[shape][rotate][y][x] == 2) {
                if (boards[BlockCOL + y][BlockROW + x] == 1 || boards[BlockCOL + y][BlockROW + x] >= 3) {
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
                    boards[BlockCOL + y][BlockROW + x] = shape + 3;//3,4,5,6,7,8,9
                    GotoXY(Pos.X + x * 2, Pos.Y + y);
                    addBlockColor(shape);
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
    IsNextBLock = true;
}
boolean IsMaxLine() {
    for (int y = Board_Height - 2; y > 1; y--) {
        int count = 0;
        for (int x = 1; x < Board_Width - 1; x++) {
            if (boards[y][x] >= 3)
                ++count;
            if (count >= 12)
                return true;
        }
    }
    return false;
}
void deleteLine() {

    COORD Pos = Cursor = getCursor();
    for (int y = Board_Height - 2; y > 0; y--) {
        int count = 0;
        for (int x = 1; x < Board_Width - 1; x++) {
            if (boards[y][x] >= 3)
                ++count;
            if (count >= 12) {
                int height = y;
                score += 1000;
                for (int x = 1; x < Board_Width - 1; x++) { //블럭 사라지는 이펙트
                    boards[height][x] = 0;
                    GotoXY(x * 2 + BoardX, height + BoardY);
                    if (boards[height][x] == 0) {
                        printf("  "); Sleep(15);
                    }
                }
                for (int x = 1; x < Board_Width - 1; x++) {
                    if (boards[height][x] == 0) {
                        GotoXY(x * 2 + BoardX, height + BoardY);
                        printf("□");
                    }
                }Sleep(150);
                for (int x = 1; x < Board_Width - 1; x++) {
                    if (boards[height][x] == 0) {
                        GotoXY(x * 2 + BoardX, height + BoardY);
                        printf("  ");
                    }
                }Sleep(90);
                for (int x = 1; x < Board_Width - 1; x++) {
                    if (boards[height][x] == 0) {
                        GotoXY(x * 2 + BoardX, height + BoardY);
                        printf("□");
                    }
                }Sleep(70);
                for (int x = 1; x < Board_Width - 1; x++) {
                    if (boards[height][x] == 0) {
                        GotoXY(x * 2 + BoardX, height + BoardY);
                        printf("  ");
                    }
                }
                Sleep(50);
                for (height; height > 0; height--) { //한 줄 제거한 height기준으로
                    for (int x = 1; x < Board_Width - 1; x++) {
                        boards[height][x] = boards[height - 1][x];
                        if (boards[height - 1][x] == 0 || boards[height - 1][x] >= 3) {
                            GotoXY(x * 2 + BoardX, height + BoardY);
                            printf("  ");
                        }
                    }
                }
                // height = y; //이거 그냥포문에넜는데 안먹히면 다시 //풀자
                for (height = y; height > 0; height--) {
                    for (int x = 1; x < Board_Width - 1; x++) {
                        if (boards[height][x] >= 3 && boards[height][x] <= 9) {
                            GotoXY(x * 2 + BoardX, height + BoardY);
                            //문제점 색깔이 갑자기 흰색으로 바뀌었다.! 이걸 해결하기위해 현재 커서에위치한 색을 반환하여,...
                            //printf("■");
                           // int colorType = getcolor();//d여기 문제있음************
                            colorRetention(boards[height][x] - 3);//여기 좀 이상하네..
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
                printScore();
                return;
            }
        }
    }
    GotoXY(Cursor.X, Cursor.Y);
    printScore();
}
void newBlock() {
    turn = 0;
    NextShape();
    CurrentShape();
    NextShape();
    Cursor.X = BlockStartX;
    Cursor.Y = BlockStartY;
}
void tetris_process() {
    system("mode con cols=110 lines=40 | title tetris_양승현");
    createBoards();
    srand(time(NULL));
    newBlock();
    InGameFrame();
    ShowNextBlock();
    Sleep(1000);
    while (1) {
        if (IsNextBLock == true) {
            IsNextBLock = false;
            DeleteNextBlock();
            ShowNextBlock();
        }
        printBoards();
        GotoXY(Cursor.X, Cursor.Y);
        addBlock(curShape, turn);
        if (_kbhit()) {
            nkey = _getch();
            if (nkey == SPACEBAR)
            {
                while (!IsCollision(curShape, turn, Cursor.X, Cursor.Y + 1))
                {
                    deleteBlock();
                    GotoXY(Cursor.X, Cursor.Y + 1);
                    addBlock(curShape, turn);
                    if (IsCollision(curShape, turn, Cursor.X, Cursor.Y + 1) == true)
                    {
                        blockFixed(curShape, turn);
                        if (IsMaxLine())
                            deleteLine();
                        break;
                    }
                }
                continue;
            }
            if (nkey == ARROW) {
                nkey = _getch();
                int a;
                switch (nkey) {
                case UP://버그 발견/... 회전할땨 벽붙어서회전하면 그대로박힘 -수정 //해결
                    a = turn;
                    if (!IsCollision(curShape, (++a % 4), Cursor.X, Cursor.Y)) {
                        deleteBlock();
                        BlockRotate();
                        addBlock(curShape, turn);
                        continue;
                    }
                    break;
                case LEFT:
                    if (!IsCollision(curShape, turn, Cursor.X - 2, Cursor.Y)) {
                        deleteBlock();
                        GotoXY(Cursor.X - 2, Cursor.Y);
                        addBlock(curShape, turn);
                        continue;
                    }
                    break;
                case RIGHT:
                    if (!IsCollision(curShape, turn, Cursor.X + 2, Cursor.Y)) {
                        deleteBlock();
                        GotoXY(Cursor.X + 2, Cursor.Y);
                        addBlock(curShape, turn);
                        continue;
                    }
                    break;
                case DOWN:
                    if (!IsCollision(curShape, turn, Cursor.X, Cursor.Y + 2)) {
                        deleteBlock();
                        GotoXY(Cursor.X, Cursor.Y + 2);
                        addBlock(curShape, turn);
                        continue;
                    }
                    break;
                }
            }
        }
        Sleep(gameLevel);
        deleteBlock(curShape, turn);
        if (!IsCollision(curShape, turn, Cursor.X, Cursor.Y + 1))
            ++Cursor.Y;
        else {
            blockFixed(curShape, turn);
            if (IsMaxLine()) {
                deleteLine();
            }
            else if (IsOverHeight())
                exit(0);
        }
    }
}