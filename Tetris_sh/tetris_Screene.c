#include "ysh_tetris_Screen.h"
void textcolor(int color_number) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}
void createBoards() {
	for (int i = 0; i < Board_Height; i++) {
		boards[i][0] = 1;
		boards[i][Board_Width - 1] = 1;
		for (int j = 0; j < Board_Width; j++) {
			if (i == 0)
				boards[i][j] = 1;

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

	/*for (int y = 0; y < Board_Height; y++) {
		for (int x = 0; x < Board_Width; x++) {
			GotoXY(BoardX+x*2, BoardY+y);
			if (boards[y][x] == 1) {
				textcolor(11);	//햐얀색
				printf("▨");
				textcolor(15);	//흰색
			}
			else if (boards[y][x] == 0)
				printf("  ");
		}
		printf("\n");
	}*/
}
//void IsBottomFull(){}
void rotateBlock(int shape, int rotate) {
	COORD Pos = Cursor = getCursor();
	BlockROW = Cursor.X / 2 - BoardX;
	BlockCOL = Cursor.Y - BoardY;
	for (int y = 0; y < Blocks_SIZE; y++) {
		for (int x = 0; x < Blocks_SIZE; x++) {
			boards[BlockCOL + y][BlockROW + x] = Blocks[shape][2][x][y];
			if (boards[BlockCOL + y][BlockROW + x] == 1)
				printf("▩");
		}
	}
	GotoXY(Cursor.X, Cursor.Y);
}
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

	BlockROW = Pos.X / 2 - BoardX;
	BlockCOL = Pos.Y - BoardY;
	if (!IsCollision(shape, rotate)) {
		for (int y = 0; y < Blocks_SIZE; y++) {
			for (int x = 0; x < Blocks_SIZE; x++) {
				boards[BlockCOL + y][BlockROW + x] = Blocks[shape][rotate][y][x];
				if (boards[BlockCOL + y][BlockROW + x] == 1) {
					GotoXY(Pos.X + x * 2, Pos.Y + y);
					printf("▩");
				}
			}
		}
	}
	GotoXY(Cursor.X, Cursor.Y); //함수가끝나면 다시 원래 블록 시작할때위치로 이동,
}
void deleteBlock() {
	COORD Pos = getCursor();
	Cursor = getCursor();
	BlockROW = Pos.X / 2 - BoardX;
	BlockCOL = Pos.Y - BoardY;
	for (int y = 0; y < Blocks_SIZE; y++) {
		for (int x = 0; x < Blocks_SIZE; x++) {
			if (boards[BlockCOL + y][BlockROW + x] == 1) {
				GotoXY(Pos.X + x * 2, Pos.Y + y); //이 좌표를 설정하지 않으면 쭈우우우욱 출력된다!
				printf("  ");
			}
		}
	}GotoXY(Cursor.X, Cursor.Y);
}
void downBlock() {

}
/*void printBlocks(int Shape) { //이렇게 할 경우 블록과 구분하기 힘듬(동일하게 적용됨)

	for (int i = 0; i < Blocks_SIZE; i++) {
		for (int j = 0; j < Blocks_SIZE; j++) {
			if (Blocks[Shape][turn][i][j] == 1) {
				printf("■");
			}
			else if (Blocks[Shape][turn][i][j] == 0)
				printf("  ");
		}
		printf("\n");
	}
}*/