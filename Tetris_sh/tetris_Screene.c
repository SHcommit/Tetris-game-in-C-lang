/**
*
* ysh_tetris_consoleCursor.h 헤더파일을 #include 합니다.
* 정의된 getChroor() 메서드를 사용하기 위함입니다.
*/
#include "ysh_tetris_Screen.h"
#include "ysh_tetris_consoleCursor.h"
int NextBlock[6][6] = {
		1,1,1,1,1,1,
		1,0,0,0,0,1,
		1,0,0,0,0,1,
		1,0,0,0,0,1,
		1,0,0,0,0,1,
		1,1,1,1,1,1,
};
void textcolor(int color_number) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}
void GameTitle() {
	int TETRIS_X = 30;
	int TETRIS_Y = 5;
	int picture_X = TETRIS_X + 5 * 2;
	int picture_Y = TETRIS_Y + 7;
	char introduce[34] = { "MADE BY _Yang seunghyun" };

	GotoXY(4, 4);
	printf("☞ VISIT MY BLOG.         https://dev-with-precious-dreams.tistory.com/"); Sleep(30);
	int tetris[5][24] = {
		1,1,1,1,1,2,2,2,3,3,3,3,3,4,4,4,4,3,3,3,0,5,5,5,
		0,0,1,0,0,2,0,0,0,0,3,0,0,4,0,0,4,0,3,0,5,0,0,0,
		0,0,1,0,0,2,2,2,0,0,3,0,0,4,4,4,4,0,3,0,0,5,5,0,
		0,0,1,0,0,2,0,0,0,0,3,0,0,4,0,4,0,0,3,0,0,0,0,5,
		0,0,1,0,0,2,2,2,0,0,3,0,0,4,0,0,4,3,3,3,5,5,5,0
	};
	int picture[3][16] = {
		6,6,6,2,1,1,4,4,4,4,1,1,0,0,5,5,
		1,1,6,2,1,1,3,0,0,3,1,1,0,0,5,7,
		1,1,2,2,3,3,3,3,3,3,4,4,4,4,5,7
	};
	int L_picture[5][5] = {
		6,6,7,7,7,
		6,6,7,0,4,
		2,2,2,4,4,
		1,2,5,5,4,
		1,1,1,5,5
	};

	int U_picture[2][19] = {
		1,1,2,2,2,3,0,4,0,1,1,0,0,3,1,1,2,2,2,
		0,1,1,2,3,3,3,4,4,4,1,1,3,3,3,1,1,2,0
	};

	int R_picture[3][3] = {
		1,1,0,
		2,1,1,
		2,2,2
	};
	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 24; x++) {
			if (tetris[y][x] == 0) {
				GotoXY(TETRIS_X + x * 2, TETRIS_Y + y);
				printf("  "); Sleep(3);
			}
			else if (tetris[y][x] == 1)
			{
				textcolor(YELLOW);
				GotoXY(TETRIS_X + x * 2, TETRIS_Y + y);
				printf("□");
				textcolor(15); Sleep(35);
			}
			else if (tetris[y][x] == 2) {
				GotoXY(TETRIS_X + x * 2, TETRIS_Y + y);
				textcolor(BLUE);
				printf("□");
				textcolor(15); Sleep(25);
			}
			else if (tetris[y][x] == 3) {
				GotoXY(TETRIS_X + x * 2, TETRIS_Y + y);
				textcolor(GREEN);
				printf("□");
				textcolor(15); Sleep(5);
			}
			else if (tetris[y][x] == 4) {
				GotoXY(TETRIS_X + x * 2, TETRIS_Y + y);
				textcolor(AQUA);
				printf("□");
				textcolor(15); Sleep(7);
			}
			else if (tetris[y][x] == 5) {
				GotoXY(TETRIS_X + x * 2, TETRIS_Y + y);
				textcolor(RED);
				printf("□");
				textcolor(15);
			}


		}
	}
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 16; x++) {
			GotoXY(picture_X + x * 2, picture_Y + y);
			if (picture[y][x] == 0) {
				printf("  "); Sleep(3);
			}
			else if (picture[y][x] == 1)
			{
				textcolor(BLUE);
				printf("■");
				Sleep(35);
			}
			else if (picture[y][x] == 2)
			{
				textcolor(GREEN);
				printf("■"); Sleep(35);
			}
			else if (picture[y][x] == 3)
			{
				textcolor(AQUA);
				printf("■"); Sleep(20);
			}
			else if (picture[y][x] == 4)
			{
				textcolor(RED);
				printf("■"); Sleep(10);
			}
			else if (picture[y][x] == 5)
			{
				textcolor(PURPLE);
				printf("■"); Sleep(3);
			}
			else if (picture[y][x] == 6)
			{
				textcolor(YELLOW);
				printf("■"); Sleep(5);
			}
			else if (picture[y][x] == 7)
			{
				textcolor(WHITE); printf("☆"); Sleep(10);
			}
		}
	}
	for (int i = 0; i < 34; i++) {
		GotoXY(1 + i, 1);
		putchar(introduce[i]); Sleep(50);
	}
	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 5; x++) {
			GotoXY(30 + x * 2, 10 + y);
			if (L_picture[y][x] == 0)
				printf("  ");
			else if (L_picture[y][x] == 1) {
				textcolor(YELLOW);
				printf("■");
				textcolor(15); Sleep(x * 2);
			}
			else if (L_picture[y][x] == 2) {
				textcolor(RED);
				printf("■");
				textcolor(15); Sleep(10);
			}
			else if (L_picture[y][x] == 3) {
				textcolor(GREEN);
				printf("■");
				textcolor(15); Sleep(30);
			}
			else if (L_picture[y][x] == 4) {
				textcolor(3);
				printf("■");
				textcolor(15); Sleep(x * 2);
			}
			else if (L_picture[y][x] == 5) {
				textcolor(4);
				printf("■");
				textcolor(15); Sleep(x * 2);
			}
			else if (L_picture[y][x] == 6) {
				textcolor(GRAY);
				printf("■");
				textcolor(15); Sleep(x * 2);
			}
			else if (L_picture[y][x] == 3) {
				textcolor(GRAY);
				printf("■");
				textcolor(15); Sleep(x * 4);
			}


		}
	}Sleep(500);
	for (int y = 0; y < 2; y++) {
		for (int x = 0; x < 19; x++) {
			GotoXY(40 + x * 2, 10 + y);
			if (U_picture[y][x] == 0)
				printf("  ");
			else if (U_picture[y][x] == 1) {
				textcolor(YELLOW);
				printf("■");
				textcolor(15); Sleep(x * 2);
			}
			else if (U_picture[y][x] == 2) {
				textcolor(BLUE);
				printf("■");
				textcolor(15); Sleep(x * 2);
			}
			else if (U_picture[y][x] == 3) {
				textcolor(GREEN);
				printf("■");
				textcolor(15); Sleep(x * 2);
			}
			else if (U_picture[y][x] == 4) {
				textcolor(3);
				printf("■");
				textcolor(15); Sleep(x * 2);
			}
		}
	}
	Sleep(700);
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			GotoXY(72 + x * 2, 12 + y);
			if (R_picture[y][x] == 0)
				printf("  ");
			else if (R_picture[y][x] == 1) {
				textcolor(AQUA);
				printf("■");
				textcolor(15); Sleep(x * 10);
			}
			else if (R_picture[y][x] == 2) {
				textcolor(4);
				printf("■");
				textcolor(15); Sleep(x * 10);
			}
		}
	}
	Sleep(500);
	GotoXY(TETRIS_X, picture_Y + 5);
	printf("Game LEVEL");
	GotoXY(TETRIS_X + 11, picture_Y + 5);
	textcolor(YELLOW);
	printf("( easy = 0, normal = 1, hard = 2 )\n");
	textcolor(WHITE);
	CursorView(true);
	GotoXY(TETRIS_X, picture_Y + 6);
	scanf_s("%d", &level);
	CursorView(false);
	switch (level) {
	case 0:
		gameLevel = easy;
		system("cls");
		break;
	case 1:
		gameLevel = normal;
		system("cls");
		break;
	case 2:
		gameLevel = hard;
		system("cls");
		break;
	}
}
void InGameFrame() {
	int picture_X = 36;//14*2+4+8 //2+14+2 = 18//
	int picture_Y = 0;
	int SecPicture[3][19] = {
		0,0,0,2,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,
		0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,1,0,1,0,
		0,0,0,0,0,2,0,0,0,0,0,0,0,2,0,0,0,0,0
	};
	int picture[9][14] = {
		0,0,0,0,0,0,0,0,2,0,0,2,2,2,
		0,0,1,1,0,1,1,0,0,2,0,2,2,2,
		0,1,0,0,1,0,0,1,0,0,0,0,2,2,
		0,0,0,0,1,0,0,0,0,0,0,2,0,0,
		0,0,0,0,1,0,0,0,0,0,2,0,0,2,
		0,0,0,3,3,3,0,0,0,0,0,0,0,0,
		0,0,3,5,3,3,3,3,0,0,0,0,3,0,
		4,3,3,3,3,3,3,3,3,3,4,3,3,4,
		4,3,3,3,3,3,3,3,3,3,3,3,3,4,
	};
	for (int y = 0; y < 9; y++) {
		for (int x = 0; x < 14; x++) {
			GotoXY(picture_X + x * 2, picture_Y + y);
			if (picture[y][x] == 0) {

				textcolor(AQUA);
				printf("■");
			}
			else if (picture[y][x] == 1)
				printf("■");
			else if (picture[y][x] == 2) {
				Sleep(5);
				textcolor(YELLOW);
				printf("■");
			}
			else if (picture[y][x] == 3) {
				textcolor(BLUE);
				printf("■");
			}
			else if (picture[y][x] == 4) {
				Sleep(8);
				textcolor(1);
				printf("■");
			}
			else if (picture[y][x] == 5)
				printf("▣");
			textcolor(WHITE);

		}
	}
	for (int y = 0; y < 3; y++) {
		for (int x = 19; x > 0; x--) {
			GotoXY(x * 2 - 2, y);
			if (SecPicture[y][x] == 0) {
				Sleep(10);
				textcolor(AQUA);
				printf("■");
			}
			else if (SecPicture[y][x] == 1) {
				Sleep(5);
				textcolor(YELLOW);
				printf("★");
			}
			else if (SecPicture[y][x] == 2) {
				Sleep(5);
				textcolor(YELLOW);
				printf("☆");
			}
			textcolor(WHITE);
		}
	}
	GotoXY(picture_X, picture_Y + 19);
	switch (level) {
	case 0:
		printf("⊙ gameLevel : easy");
		break;
	case 1:
		printf("⊙ gameLevel : normal");
		break;
	case 2:
		printf("⊙ gameLevel : hard");
		break;
	}
	GotoXY(picture_X, picture_Y + 21);
	printf("⊙ game KEY");
	printScore();
	GotoXY(picture_X, picture_Y + 22);
	printf("  ▲         : block rotate");
	GotoXY(picture_X, 23);
	printf("◀  ▶       : move LEFT /  move RIGHT");
	GotoXY(picture_X, 24);
	printf("  ▼         : move DOWN");
	GotoXY(picture_X, 25);
	printf("■■■■     : space BAR (DIRECT DOWN)");
	for (int i = 0; i < 3; i++) {
		GotoXY(picture_X, picture_Y + 21);
		printf("⊙ game KEY");
		Sleep(350);
		GotoXY(picture_X, picture_Y + 21);
		printf("            ");
		Sleep(250);
	}
	GotoXY(picture_X, picture_Y + 21);
	printf("            ");
	GotoXY(picture_X, picture_Y + 21);
	printf("⊙ game KEY");
}
void ShowNextBlock() {
	GotoXY(36 + 9, 0 + 11);
	textcolor(DARKPURPLE);
	printf("NEXT BLOCK");
	textcolor(WHITE);
	for (int y = 0; y < 6; y++) {
		for (int x = 0; x < 6; x++) {
			GotoXY(36 + 8 + x * 2, 12 + y);
			if (NextBlock[y][x] == 1) {
				textcolor(3);//6
				printf("▩");
				textcolor(WHITE);
			}
			if (y > 0 && y < 5) {
				if (x > 0 && x < 5) {
					if (Blocks[nexShape][0][y - 1][x - 1] == 2)
					{
						NextBlock[y][x] = Blocks[nexShape][0][y - 1][x - 1];
						GotoXY(36 + 8 + x * 2, 12 + y);
						printf("■");
					}
				}
			}
		}

	}
}
void DeleteNextBlock() {
	for (int y = 0; y < 6; y++) {
		for (int x = 0; x < 6; x++) {
			if (y > 0 && y < 5) {
				if (x > 0 && x < 5) {
					if (NextBlock[y][x] == 2) {
						GotoXY(36 + 8 + x * 2, 12 + y);
						printf("  ");
					}
				}
			}
		}
	}
}
void createBoards() {
	for (int i = 0; i < BoardHeight; i++) {
		board[i][0] = 1;
		board[i][BoardWidth - 1] = 1;
		for (int j = 0; j < BoardWidth; j++) {
			if (i == 0)
				board[i][j] = 0;
			board[BoardHeight - 1][j] = 1;
			if (i > 0 && i < BoardHeight - 1)
				if (j > 0 && j < BoardWidth - 1)
					board[i][j] = 0;
		}
	}
}
void printBoards() {
	for (int x = 1; x < 13; x++) {
		GotoXY(BoardX + x * 2, BoardY + 1);
		printf("＿");
	}

	for (int y = 0; y < BoardHeight; y++) {
		GotoXY(BoardX, BoardY + y);
		if (board[y][0] == 1) {
			textcolor(3);	printf("▩");
		}
		if (board[y][BoardWidth - 1] == 1) {
			GotoXY(BoardX + BoardWidth * 2 - 2, BoardY + y);
			textcolor(3);
			printf("▩");
		}
		textcolor(WHITE);
	}
	for (int x = 0; x < BoardWidth; x++) {
		GotoXY(BoardX + x * 2, BoardY + BoardHeight - 1);
		if (board[BoardHeight - 1][x] == 1) {
			textcolor(3);	printf("▩");
		}
		textcolor(WHITE);
	}

}
void addBlock(int shape, int rotate) {
	COORD Pos = Cursor = getCursor();
	BlockROW = Pos.X / 2 - BoardX / 2;
	BlockCOL = Pos.Y - BoardY;
	for (int y = 0; y < BlockSIZE; y++) {
		for (int x = 0; x < BlockSIZE; x++) {
			if (Blocks[shape][rotate][y][x] == 2) {
				board[BlockCOL + y][BlockROW + x] = 2;
				GotoXY(Pos.X + x * 2, Pos.Y + y);
				addCurrentBlockColor();
			}
		}
	}
	GotoXY(Cursor.X, Cursor.Y);
}
void deleteBlock() {
	COORD Pos = Cursor = getCursor();
	BlockROW = Pos.X / 2 - BoardX / 2;
	BlockCOL = Pos.Y - BoardY;
	for (int y = 0; y < BlockSIZE; y++) {
		for (int x = 0; x < BlockSIZE; x++) {
			if (board[BlockCOL + y][BlockROW + x] == 2) {
				GotoXY(Pos.X + x * 2, Pos.Y + y);
				printf("  ");
			}
		}
	}
	GotoXY(Cursor.X, Cursor.Y);
}
void EndGameFrame() {
	for (int y = 1; y < BoardHeight - 1; y++) {
		for (int x = 1; x < BoardWidth - 1; x++) {
			if (board[y][x] >= 3) {
				GotoXY(BoardX + x * 2, BoardY + y);
				printf("▣");
			}
		}
		Sleep(150 - y * 5);
	}
	GotoXY(BlockStartX, BlockStartY + 1);
	printf("GameOVER");
	Sleep(3000);
	exit(0);
}