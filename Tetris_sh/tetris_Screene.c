#include "ysh_tetris_Screen.h"
void textcolor(int color_number) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}
/*void changedBoard() { //이거 좀고쳐야함, 이거랑 그리고 블록12개되면사라지는데, 안내려가네? ㅇ
	Cursor = getCursor();//이거는 내려간 블록을 ㅅ로 추가하기위해만들었는데 괜히만들었나 하기도함
	COORD Pos;
	Pos.X = BoardX; Pos.Y = BoardY;
	BlockROW = Pos.X / 2 - BoardX / 2;
	BlockCOL = Pos.Y - BoardY;
	for(int y = 1; y < Board_Height-1; y++) {
		for (int x = 1; x < Board_Width-1; x++) {
			if (boards[BlockCOL + y][BlockROW + x] == 1) {
				GotoXY(Pos.X + x * 2, Pos.Y + y);
				printf("■");
			}
		}
	}
	GotoXY(Cursor.X, Cursor.Y);
}*/
void createBoards() {
	for (int i = 0; i < Board_Height; i++) {
		boards[i][0] = 1;
		boards[i][Board_Width - 1] = 1;
		for (int j = 0; j < Board_Width; j++) {
			if (i == 0)
				boards[i][j] = 0;

			boards[Board_Height - 1][j] = 1;
			if (i > 0 && i < Board_Height - 1)
				if (j > 0 && j < Board_Width - 1)
					boards[i][j] = 0;
		}
	}
}
void printBoards() {
	GotoXY(BoardX, BoardY);
	for (int y = 0; y < Board_Height; y++) {
		GotoXY(BoardX, BoardY + y);
		if (boards[y][0] == 1) {
			textcolor(11);	//햐얀색
			printf("▨");
			textcolor(15);
		}
		if (boards[y][Board_Width - 1] == 1) {
			GotoXY(BoardX + Board_Width * 2 - 2, BoardY + y);
			textcolor(11);	//햐얀색
			printf("▨");
			textcolor(15);
		}
	}
	for (int x = 0; x < Board_Width; x++) {
		GotoXY(BoardX + x * 2, BoardY + Board_Height - 1);
		if (boards[Board_Height - 1][x] == 1) {
			textcolor(11);	//햐얀색
			printf("▨");
			textcolor(15);
		}
	}

}
/*void rotateBlock(int shape, int rotate) {
	COORD Pos = Cursor = getCursor();
	BlockROW = Cursor.X/2 - BoardX;
	BlockCOL = Cursor.Y - BoardY;
	for (int y = 0; y < Blocks_SIZE; y++) {
		for (int x = 0; x < Blocks_SIZE; x++) {
			boards[BlockCOL + y][BlockROW + x] = Blocks[shape][rotate][y][x];
			if (boards[BlockCOL + y][BlockROW + x] == 2 )
				printf("▣");
		}
	}
}*/
/*void addBlock(int shape) {
	COORD Pos=Cursor=getCursor();
	BlockROW = Cursor.X - BoardX;
	BlockCOL = Cursor.Y - BoardY;
	for (int y = 0; y < Blocks_SIZE; y++) {
		for (int x = 0; x < Blocks_SIZE; x++) {
			boards[BlockCOL+y][BlockROW+x] = Blocks[shape][2][x][y]; //문제는 여기의 x,y를 y,x로
			//printf("%d", Blocks[4][3][y][x]);
			//printf("%d", boards[BlockCOL + y][BlockROW + x]); //둘다 개별적으로 블록의 형태를 잘 받았다.
			if(boards[BlockCOL+y][BlockROW+x]==1)
				printf("▩"); //문제는 여기다. 이 좌표를 직접 지정하지 않나서 그런 문제가 발생한것이다.
		}			//이 세문장 때문에 1시간을 소비하다니;;
	}
	GotoXY(Cursor.X,Cursor.Y); //함수가끝나면 다시 원래 블록 시작할때위치로 이동,
}*/
void addBlock(int shape, int rotate) {
	COORD Pos = Cursor = getCursor(); //두개를 선언하는 이유는 포문이 끝나면 커서가 다시 원위치로 돌아가야 한칸 아래씩 전부 내려갈수있기대문
	BlockROW = Pos.X / 2 - BoardX / 2;
	BlockCOL = Pos.Y - BoardY;
	for (int y = 0; y < Blocks_SIZE; y++) {
		for (int x = 0; x < Blocks_SIZE; x++) {
			//boards[BlockCOL + y][BlockROW + x] = Blocks[shape][rotate][y][x]; //이 문장이 잘못됬네,, 주변에 0도 다 0으로 바꾸니까 벽을 인식못해 벽조차 0이됨 ㅋ
			if (Blocks[shape][rotate][y][x] == 2) {
				boards[BlockCOL + y][BlockROW + x] = 2;
				GotoXY(Pos.X + x * 2, Pos.Y + y);
				printf("□");
			}
		}
	}
	GotoXY(Cursor.X, Cursor.Y); //함수가끝나면 다시 원래 블록 시작할때위치로 이동,
}
void deleteBlock() {
	COORD Pos = Cursor = getCursor();
	BlockROW = Pos.X / 2 - BoardX / 2;
	BlockCOL = Pos.Y - BoardY;
	for (int y = 0; y < Blocks_SIZE; y++) {
		for (int x = 0; x < Blocks_SIZE; x++) {
			if (boards[BlockCOL + y][BlockROW + x] == 2) {
				GotoXY(Pos.X + x * 2, Pos.Y + y); //이 좌표를 설정하지 않으면 쭈우우우욱 출력된다!
				printf("  "); //이것도 
			}
		}
	}
	GotoXY(Cursor.X, Cursor.Y);
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