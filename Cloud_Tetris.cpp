// 테트리스 가로 세로 공간 크기 ( 18 x 9 )
//올린 날자 현제 2016-07-23

#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

#define LEFT 75 // Go Left
#define RIGHT 77 // Go Right
#define UP 72 // Turn
#define DOWN 80 // Quick Drop
#define MOVEAR 224 // 키보드 화살표 값 'MoveArrow'
#define SPACE 32 // Hard Drop
#define ESC 27 // Exit The Game

#define WALL_X_MIN 5
#define WALL_X_MAX 15
#define WALL_Y_MIN 0
#define WALL_Y_MAX 23

#define EMPTY 0
#define WALLS 2
#define BLOCK 1

#define SLOW_ 800

#define CLEAR system("cls");

int blocks[7][4][4][4]= {
	{{0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0},{0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0},{0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0},{0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0}},
	{{0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0},{0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0},{0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0},{0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0}},
	{{0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0},{0,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0},{0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0},{0,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0}},
	{{0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0},{0,0,0,0,1,0,0,0,1,1,0,0,0,1,0,0},{0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0},{0,0,0,0,1,0,0,0,1,1,0,0,0,1,0,0}},
	{{0,0,0,0,0,0,1,0,1,1,1,0,0,0,0,0},{0,0,0,0,1,1,0,0,0,1,0,0,0,1,0,0},{0,0,0,0,0,0,0,0,1,1,1,0,1,0,0,0},{0,0,0,0,0,1,0,0,0,1,0,0,0,1,1,0}},
	{{0,0,0,0,1,0,0,0,1,1,1,0,0,0,0,0},{0,0,0,0,0,1,0,0,0,1,0,0,1,1,0,0},{0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,0},{0,0,0,0,0,1,1,0,0,1,0,0,0,1,0,0}},
	{{0,0,0,0,0,1,0,0,1,1,1,0,0,0,0,0},{0,0,0,0,0,1,0,0,0,1,1,0,0,1,0,0},{0,0,0,0,0,0,0,0,1,1,1,0,0,1,0,0},{0,0,0,0,0,1,0,0,1,1,0,0,0,1,0,0}}
};
int block_type=0;
int block_next;
int block_turn;
int block_height=0;

int wall_x=5;
int wall_y=3;

int block_x=0;
int block_y=0;

int rand_ground;



void gotoxy(int x,int y) { // Windows API    좌표함수
	COORD c= {x*2,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

void GameScreen(void) {
	int i;
	for(i=0; i<23; i++) {
		gotoxy(5,i);
		printf("▩"); //5,0~22
		gotoxy(15,i);
		printf("▩"); //15,0~22
	}
	for(i=0; i<11; i++) {
		gotoxy(i+5,23);
		printf("▩");//5~15,23(6~14,23)
	}

}

typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE; //커서안보이게하는 함수에 사용되는 열거형
void setcursortype(CURSOR_TYPE c) { //커서 안보이게 하는 함수
	CONSOLE_CURSOR_INFO CurInfo;

	switch (c) {
		case NOCURSOR:
			CurInfo.dwSize=1;
			CurInfo.bVisible=FALSE;
			break;
		case SOLIDCURSOR:
			CurInfo.dwSize=100;
			CurInfo.bVisible=TRUE;
			break;
		case NORMALCURSOR:
			CurInfo.dwSize=20;
			CurInfo.bVisible=TRUE;
			break;
	}
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&CurInfo);
}

void StartScreen(void); // 프로그램 시작시 호출하는 함수
void new_block(int heigth); // 새로운 블럭 생성
int check_crash(void); // 블럭이 벽이나 설치된 블럭 등 출돌이 일어나는지 확인
void block_move(void);


int main() {                                   /*------------------------------     main function     -----------------------------------*/ 
	int start_games=1;
	int i=0;

	srand((unsigned)time(NULL));
	setcursortype(NOCURSOR);
	StartScreen();

	for(i=0; ; i++) {
		if(rand_ground==1||start_games==1) {
			new_block(block_height);
			start_games=0;
		}
		if(i==1000){
			i=0;
			Sleep(1000);
			if(check_crash()==1){
				block_height+=1;
			}
		}
		Sleep(1);
	}

	getch();
	return 0;
}

void StartScreen() {
	int x=3,y=2;
	gotoxy(x,y);
	printf("■■■  ■      ■■■  ■  ■  ■■  \n");//1
	gotoxy(x,y+1 );
	printf("■      ■      ■  ■  ■  ■  ■  ■   made\n");//2
	gotoxy(x,y+2 );
	printf("■      ■      ■  ■  ■  ■  ■  ■    by\n");//3
	gotoxy(x,y+3 );
	printf("■      ■      ■  ■  ■  ■  ■  ■  yoonki\n");//4
	gotoxy(x,y+4 );
	printf("■■■  ■■■  ■■■  ■■■  ■■  \n");//5
	gotoxy(x,y+5 );
	printf("\n");//6
	gotoxy(x,y+6 );
	printf("■■■    ■      ■    ■  ■    ■      ■■\n");//7
	gotoxy(x,y+7 );
	printf("  ■    ■  ■  ■■■  ■■            ■    \n");//8
	gotoxy(x,y+8 );
	printf("  ■    ■■■    ■    ■        ■      ■  \n");//9
	gotoxy(x,y+9 );
	printf("  ■    ■        ■    ■        ■        ■\n");//10
	gotoxy(x,y+10);
	printf("  ■      ■■    ■    ■        ■    ■■  \n");//11

	getch();
	CLEAR;
	GameScreen();
}

void new_block(int height) {  // 블럭 "생성" 만 하는 함수 
	int x=8,y=0;
	int i,j;
	block_type=rand()%7;
	for(i=0; i<4; i++) {
		for(j=0; j<4; j++) {
			if(blocks[block_type][block_turn][i][j]==1) {
				gotoxy(x+i,y+j);
				printf("▣");
			}
			if(blocks[block_type][block_turn][i][j]==0) {
				gotoxy(x+i,y+j);
				printf("  ");
			}
		}
	}
}

int check_crash (void) { // 충돌 할시 1, 아닐시 0을 반환. (block_height 값을 0으로 지정) 
	 
}

void block_move (void) {
	
}
