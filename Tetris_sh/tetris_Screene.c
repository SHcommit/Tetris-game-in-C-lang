#include "ysh_tetris_Screen.h"
void textcolor(int color_number) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}
/*void changedBoard() { //�̰� �����ľ���, �̰Ŷ� �׸��� ���12���Ǹ������µ�, �ȳ�������? ��
	Cursor = getCursor();//�̰Ŵ� ������ ����� ���� �߰��ϱ����ظ�����µ� ����������� �ϱ⵵��
	COORD Pos;
	Pos.X = BoardX; Pos.Y = BoardY;
	BlockROW = Pos.X / 2 - BoardX / 2;
	BlockCOL = Pos.Y - BoardY;
	for(int y = 1; y < Board_Height-1; y++) {
		for (int x = 1; x < Board_Width-1; x++) {
			if (boards[BlockCOL + y][BlockROW + x] == 1) {
				GotoXY(Pos.X + x * 2, Pos.Y + y);
				printf("��");
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
			textcolor(11);	//����
			printf("��");
			textcolor(15);
		}
		if (boards[y][Board_Width - 1] == 1) {
			GotoXY(BoardX + Board_Width * 2 - 2, BoardY + y);
			textcolor(11);	//����
			printf("��");
			textcolor(15);
		}
	}
	for (int x = 0; x < Board_Width; x++) {
		GotoXY(BoardX + x * 2, BoardY + Board_Height - 1);
		if (boards[Board_Height - 1][x] == 1) {
			textcolor(11);	//����
			printf("��");
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
				printf("��");
		}
	}
}*/
/*void addBlock(int shape) {
	COORD Pos=Cursor=getCursor();
	BlockROW = Cursor.X - BoardX;
	BlockCOL = Cursor.Y - BoardY;
	for (int y = 0; y < Blocks_SIZE; y++) {
		for (int x = 0; x < Blocks_SIZE; x++) {
			boards[BlockCOL+y][BlockROW+x] = Blocks[shape][2][x][y]; //������ ������ x,y�� y,x��
			//printf("%d", Blocks[4][3][y][x]);
			//printf("%d", boards[BlockCOL + y][BlockROW + x]); //�Ѵ� ���������� ����� ���¸� �� �޾Ҵ�.
			if(boards[BlockCOL+y][BlockROW+x]==1)
				printf("��"); //������ �����. �� ��ǥ�� ���� �������� �ʳ��� �׷� ������ �߻��Ѱ��̴�.
		}			//�� ������ ������ 1�ð��� �Һ��ϴٴ�;;
	}
	GotoXY(Cursor.X,Cursor.Y); //�Լ��������� �ٽ� ���� ��� �����Ҷ���ġ�� �̵�,
}*/
void addBlock(int shape, int rotate) {
	COORD Pos = Cursor = getCursor(); //�ΰ��� �����ϴ� ������ ������ ������ Ŀ���� �ٽ� ����ġ�� ���ư��� ��ĭ �Ʒ��� ���� ���������ֱ�빮
	BlockROW = Pos.X / 2 - BoardX / 2;
	BlockCOL = Pos.Y - BoardY;
	for (int y = 0; y < Blocks_SIZE; y++) {
		for (int x = 0; x < Blocks_SIZE; x++) {
			//boards[BlockCOL + y][BlockROW + x] = Blocks[shape][rotate][y][x]; //�� ������ �߸����,, �ֺ��� 0�� �� 0���� �ٲٴϱ� ���� �νĸ��� ������ 0�̵� ��
			if (Blocks[shape][rotate][y][x] == 2) {
				boards[BlockCOL + y][BlockROW + x] = 2;
				GotoXY(Pos.X + x * 2, Pos.Y + y);
				printf("��");
			}
		}
	}
	GotoXY(Cursor.X, Cursor.Y); //�Լ��������� �ٽ� ���� ��� �����Ҷ���ġ�� �̵�,
}
void deleteBlock() {
	COORD Pos = Cursor = getCursor();
	BlockROW = Pos.X / 2 - BoardX / 2;
	BlockCOL = Pos.Y - BoardY;
	for (int y = 0; y < Blocks_SIZE; y++) {
		for (int x = 0; x < Blocks_SIZE; x++) {
			if (boards[BlockCOL + y][BlockROW + x] == 2) {
				GotoXY(Pos.X + x * 2, Pos.Y + y); //�� ��ǥ�� �������� ������ �޿���� ��µȴ�!
				printf("  "); //�̰͵� 
			}
		}
	}
	GotoXY(Cursor.X, Cursor.Y);
}