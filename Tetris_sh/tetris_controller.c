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
void printScore() {
    GotoXY(36, 20);
    printf("�� Score : %d", score);
}
/*void colorRetention(int colorType) { //deleteLine�� ����� �����ö� �����ִ� �� �״�� ���!
    switch (colorType) {
    case BLUE:
        textcolor(BLUE);
        printf("��");
        textcolor(WHITE);
        break;
    case GREEN:
        textcolor(GREEN);
        printf("��");
        textcolor(WHITE);
        break;
    case AQUA:
        textcolor(AQUA);
        printf("��");
        textcolor(WHITE);
        break;
    case RED:
        textcolor(RED);
        printf("��");
        textcolor(WHITE);
        break;
    case PURPLE:
        textcolor(PURPLE);
        printf("��");
        textcolor(WHITE);
        break;
    case YELLOW:
        textcolor(YELLOW);
        printf("��");
        textcolor(WHITE);
        break;
    case WHITE:
        textcolor(GRAY);
        printf("��");
        textcolor(WHITE);
        break;
    }
}*/
void colorRetention(int colorType) {
    switch (colorType) {
    case 0:
        textcolor(BLUE);
        printf("��");
        textcolor(WHITE);
        break;
    case 1:
        textcolor(GREEN);
        printf("��");
        textcolor(WHITE);
        break;
    case 2:
        textcolor(AQUA);
        printf("��");
        textcolor(WHITE);
        break;
    case 3:
        textcolor(RED);
        printf("��");
        textcolor(WHITE);
        break;
    case 4:
        textcolor(PURPLE);
        printf("��");
        textcolor(WHITE);
        break;
    case 5:
        textcolor(YELLOW);
        printf("��");
        textcolor(WHITE);
        break;
    case 6:
        textcolor(GRAY);
        printf("��");
        textcolor(WHITE);
        break;

    }
}

void addBlockColor() {
    switch (curShape) {
    case 0:
        textcolor(BLUE);
        printf("��");
        textcolor(WHITE);
        break;
    case 1:
        textcolor(GREEN);
        printf("��");
        textcolor(WHITE);
        break;
    case 2:
        textcolor(AQUA);
        printf("��");
        textcolor(WHITE);
        break;
    case 3:
        textcolor(RED);
        printf("��");
        textcolor(WHITE);
        break;
    case 4:
        textcolor(PURPLE);
        printf("��");
        textcolor(WHITE);
        break;
    case 5:
        textcolor(YELLOW);
        printf("��");
        textcolor(WHITE);
        break;
    case 6:
        textcolor(GRAY);
        printf("��");
        textcolor(WHITE);
        break;

    }
}
boolean IsOverHeight() {//�Ǵ� �����Ҷ� 4*4�� 1�̶� 2�� ���� ������ ���� ����
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
    BlockROW = curX / 2 - BoardX / 2; //�̰Ŵ� x��ǥ���� /2�ؾ���
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
    Cursor.X = BlockStartX; //�̰� 4�� �� �ݺ��ɼ��ִ°͵��̴ϱ�, ����. ����ü�� ��������
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
                for (int x = 1; x < Board_Width - 1; x++) { //�� ������� ����Ʈ
                    boards[height][x] = 0;
                    GotoXY(x * 2 + BoardX, height + BoardY);
                    if (boards[height][x] == 0) {
                        printf("  "); Sleep(15);
                    }
                }
                for (int x = 1; x < Board_Width - 1; x++) {
                    if (boards[height][x] == 0) {
                        GotoXY(x * 2 + BoardX, height + BoardY);
                        printf("��");
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
                        printf("��");
                    }
                }Sleep(70);
                for (int x = 1; x < Board_Width - 1; x++) {
                    if (boards[height][x] == 0) {
                        GotoXY(x * 2 + BoardX, height + BoardY);
                        printf("  ");
                    }
                }
                Sleep(50);
                for (height; height > 0; height--) { //�� �� ������ height��������
                    for (int x = 1; x < Board_Width - 1; x++) {
                        boards[height][x] = boards[height - 1][x];
                        if (boards[height - 1][x] == 0 || boards[height - 1][x] >= 3) {
                            GotoXY(x * 2 + BoardX, height + BoardY);
                            printf("  ");
                        }
                    }
                }
                // height = y; //�̰� �׳��������Դµ� �ȸ����� �ٽ� //Ǯ��
                for (height = y; height > 0; height--) {
                    for (int x = 1; x < Board_Width - 1; x++) {
                        if (boards[height][x] >= 3 && boards[height][x] <= 9) {
                            GotoXY(x * 2 + BoardX, height + BoardY);
                            //������ ������ ���ڱ� ������� �ٲ����.! �̰� �ذ��ϱ����� ���� Ŀ������ġ�� ���� ��ȯ�Ͽ�,...
                            //printf("��");
                           // int colorType = getcolor();//d���� ��������************
                            colorRetention(boards[height][x] - 3);//���� �� �̻��ϳ�..
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
    system("mode con cols=110 lines=40 | title tetris_�����");
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
                case UP://���� �߰�/... ȸ���ҋx ���پȸ���ϸ� �״�ι��� -���� //�ذ�
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