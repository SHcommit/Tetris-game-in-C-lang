#pragma once
#ifndef controller
#define controller

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#include <stdbool.h>

/**
* 게임에 출력될 음악 헤더파일과 정의입니다.
* BGM은 예를들어 "C:\\Users\\Desktop\\tetris\\음악명"
* 경로를 문자열로 저장해야합니다.
* #define으로 BGM 정의 하고 main함수에서 사용 가능.
* 근데 저작권 때문에 주석처리.
*/
#include<mmsystem.h>
#pragma comment(lib, "winmm.lib")
//경로는 \ 가아니라 \\를 해야함.
//#define BGM "C:\\Users\\SH\\Desktop\\Tetris_ysh_완전_다만듬_코드리뷰_\\Runaway.wav"


/**
* 보드 가로, 세로 길이
* 콘솔창에서 출력될 보드 출력 X, Y좌표
*/
enum boardProperty {
	BoardWidth = 14,
	BoardHeight = 22,
	BoardX = 4,
	BoardY = 3
};

enum Keys {
	LEFT = 75,
	RIGHT = 77,
	UP = 72,
	DOWN = 80,
	ARROW = 224,
	SPACEBAR = 32
};

typedef enum gameSpeed {
	easy = 230,
	normal = 170,
	hard = 150
}SPEED;

/**
* 블록의 크기
* 블록의 회전
* 블록의 종류
* 블록이 커서창에서 시작될 x, y 좌표
*/
enum blockProperty {
	BlockSIZE = 4,
	BlockRotate = 4,
	BlockType = 7,
	BlockStartX = 14,
	BlockStartY = 4
};

// 사용자가 입력한 특정 방향키 아스키 코드값
int nkey;


/**
* 지금 현재의 콘솔창에서 출력되는 '커서'가 어떤 좌표에 해당하는지 파악하는게 중요합니다.
* 제가 구현한 코드에서 특히 그렇습니다.
* 현재 위치한 콘솔안 커서 좌표 Cursor변수 를 기준으로
* 현재 블록의 모양 " curShape " 변수를 콘솔창에 출력할 수 있기 때문입니다.
*
* prevBlockCOL , prevBlockROW는 현재 블록이 한칸 아래로 내려가면,
* 이전에 출력된 블록의 위치에 해당하는 블록의 출력 이미지를 없애야 합니다.
*
* 현재 바로 이전 좌표값을 갖고 한 칸씩 내려갈 때마다, 새로운 현재 좌표값과, 과거가 되버린 이전 좌표값을 갖어야 합니다.
* 또는 현재 콘솔창의 커서 좌표값 Cursor을 기준으로 보드 안에 있는 현재 좌표값을 가지고
*	보드안에 존재하는 가로 14, 세로 22 안에 출력된 특정한 4*4크기의 첫번째 x,y index를 저장하는 방식입니다.
****다시 말해서
*		2차원 배열의 Board[22][14]안에 표시된 블록 4*4 크기의 첫번째 index , 두번째 index를 구하면
*		쉽게 블록을 출력할수도, 삭제할 수도 있습니다.
*		현재 콘솔창의 커서에 대해서 위에서 말한 첫번째 index는 특정 세로줄이 될 것인데,
*		* 그 세로줄의 첫번째 index를 BlockCOL에 저장했습니다.
*		* 가로줄인 두번째 index = BlockROW
*		**
*		*현재 Cursor이전에 위치한 커서에 대한 block안에 표시되었던 블록의 가로, 세로값은
*		* prevBlockROW, prevBlockCOL에 저장했습니다.
* 이 4개의 변수를 활용해 블록을 보드 안에서 출력할 수도, 지울 수도 있다는 말입니다.
***
* 새로운 현재 좌표값을 통해 한칸 아래 내려간 새로운 현재 좌표값에 블록을 출력하는데,
* 그 이전에 출력되었던 블록을 이전 index값(prevBlockROW&COL 변수)를 통해
* ' 2 ' -> ' 0 '으로 제거할 수 있습니다.
* 블록을 콘솔창에서 제거하는 함수는 deletePrevBlock()
*
* 콘솔창 내에서 다루어지는 좌표값은 크기가 작음으로 short로 선언했습니다.
*/
//현재 블록 모양
short curShape;
void CurrentShape();
//다음 블록 모양
short nexShape;
void NextShape();
//블록의 현재 좌표!!!
short BlockCOL;
short BlockROW;
//블록의 이전 좌표
short prevBlockCOL;
short prevBlockROW;
//테트리스 보드 내 현재 위치하는 커서
COORD Cursor;
//이전 블록 지우기
void deletePrevBlock();
//스코어
int static score;
void printScore();
//게임 난이도
short gameLevel;
//새로운 블록 종류 생성
void newBlock();


/**
* 새로운 블록인가 ? (flag느낌.)
* 새로운 블록 == true이라면 새로운 블록을 false 처리 한 후에
* ShowNextBlock()을 호출시키며 다음에 나올 블록을 인 게임 화면
* 테트리스 보드 옆에 보여준다!
*/
boolean IsNextBlock;


/**
* 회전 기능의 방향키를 입력 받을 시
* turn(현재 블록의 회전 상태 0,1,2,3중 예를들어 turn == 0번째 회전 상태(초기블럭이라면)
* ' -> ' 방향키를 통해 turn ==1이되고, 이에 따라서
* block에서 정의한
* block[특정한 블럭 모양][0][][]에서
* block[특정한 블럭 모양][1][][]로 회전된 블록이 출력될 수 있도록 turn의 상태를
* RotateBlock() 메서드를 통해 변환한다.
*/
short turn;
void RotateBlock(); //방향키 받을시 rotate 를통해 방향키 변경


/**
* IsCollision(int shape, int rotate, int curX, int curY)
* 현재 콘솔창의 커서값 Cursor에서 한칸 내려갔을 때
* 그 좌표에서 그려지는 블록이 테트리스 보드의 바닥과 닿거나,
* bottom에 블록이 닿아 고정된 블록과 닿는다면,
* true 반환
* 그럴 경우 현재 좌표값이 보드의 바닥과 닿거나, 바닥화?된(고착화된? 바닥에 얹혀진) 블록이라고 판단되기에
* 현재 좌표에 출력된 블록을 블록의 바닥으로 인식시킵니다. blockFixed(int shape, int rotate)
*/
boolean IsCollision(int shape, int rotate, int curX, int curY);
//블록이 bottom에 닿았을 경우 
void blockFixed(int shape, int rotate);


/**
* 보드의 특정 가로줄이 블록으로 저장되있는가? IsMaxLine()
* yes? -> deleteLine()
*/
boolean IsMaxLine();
void deleteLine();
//처음 생성된 블록이 천장과 닿았는가?
boolean IsOverHeight();


//미리보기 블록 만들고 지울 때 해당 좌표 저장해야합니다.
COORD previewPoint;
//미리보기 블록, 현재 블록 이후에 나올 블록 화면에 표현.
void previewBlock(int shape, int rotate);
//테트리스 돌아가는데 있어 가장 중요한 함수.(메인함수급입니다)
void tetris_process();
#endif // !controller