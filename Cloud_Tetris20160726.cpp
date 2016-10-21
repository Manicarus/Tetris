/*
-색 추가
-벽 버그 고침

-3번 블럭 오류
-블럭 내려올때 출력 버그
*/

// 테트리스 가로 세로 공간 크기 ( 25 x 10 )


#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

#define COL GetStdHandle(STD_OUTPUT_HANDLE) 
#define BLACK         SetConsoleTextAttribute(COL,0x0000); //검정색 
#define DARK_BLUE     SetConsoleTextAttribute(COL,0x0001); //파란색 
#define GREEN         SetConsoleTextAttribute(COL,0x0002); //녹색 
#define BLUE_GREEN    SetConsoleTextAttribute(COL,0x0003); //청녹생 
#define BLOOD         SetConsoleTextAttribute(COL,0x0004); //검붉은색 
#define PURPLE        SetConsoleTextAttribute(COL,0x0005); //보라색 
#define GOLE          SetConsoleTextAttribute(COL,0x0006); //금색 색 
#define ORIGINAL      SetConsoleTextAttribute(COL,0x0007); //밝은회색 
#define GRAY          SetConsoleTextAttribute(COL,0x0008); //회색 
#define BLUE          SetConsoleTextAttribute(COL,0x0009); //파란색 
#define HIGH_GREEN    SetConsoleTextAttribute(COL,0x000a); //연두색 
#define SKY_BLUE      SetConsoleTextAttribute(COL,0x000b); //하늘색 
#define RED           SetConsoleTextAttribute(COL,0x000c); //빨간색 
#define PLUM          SetConsoleTextAttribute(COL,0x000d); //자주색 
#define YELLOW        SetConsoleTextAttribute(COL,0x000e); //노란 

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
int block_turn=0;
int block_height=0;

int stop=0; //블럭이 땅에 닿았을 때 

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
		gotoxy(16,i);
		printf("▩"); //15,0~22
	}
	for(i=0; i<12; i++) {
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
void new_block(int x, int y); // 새로운 블럭 생성
int check_crash(void); // 블럭이 벽이나 설치된 블럭 등 출돌이 일어나는지 확인
void block_move(void);
void colors_(void);


int main() {                                   /*-----------------------------------     main function     -----------------------------------*/ 
	int start_games=1;
	int i=0;
	int x=8; // x좌표 키값받아서 움직임( 기본값 : 8 ) 
	srand((unsigned)time(NULL));
	setcursortype(NOCURSOR);
	StartScreen();

	for(i=0;i<1001; i++) {
		check_crash();
		if(stop==1||start_games==1) { // 블럭 충돌시 또는 게임 시작 시 
			block_type=rand()%7; 
			x=8;
			new_block(x,block_height); // 기본위치에 블럭 생성 
			start_games=0;
			stop=0;
		}
		if(i==10){
			i=0;
			Sleep(10);
			if(stop==0){
				block_height+=1;
			}
		}
		new_block(x,block_height);
		Sleep(10);
	}

	getch();
	return 0;
}

void StartScreen() {
	int x=3,y=2;
	int a=0;
	gotoxy(x , y );printf("■■■  ■      ■■■  ■  ■  ■■  \n");//1
	Sleep(100);gotoxy(x,y+1 );printf("■      ■      ■  ■  ■  ■  ■  ■   made\n");//2
	Sleep(100);gotoxy(x,y+2 );printf("■      ■      ■  ■  ■  ■  ■  ■    by\n");//3
	Sleep(100);gotoxy(x,y+3 );printf("■      ■      ■  ■  ■  ■  ■  ■  yoonki\n");//4
	Sleep(100);gotoxy(x,y+4 );printf("■■■  ■■■  ■■■  ■■■  ■■  \n");//5
	Sleep(100);
	gotoxy(x,y+5 );printf("\n");//6
	gotoxy(x,y+6 );printf("■■■    ■      ■    ■  ■    ■      ■■\n");//7
	Sleep(100);gotoxy(x,y+7 );printf("  ■    ■  ■  ■■■  ■■            ■    \n");//8
	Sleep(100);gotoxy(x,y+8 );printf("  ■    ■■■    ■    ■        ■      ■  \n");//9
	Sleep(100);gotoxy(x,y+9 );printf("  ■    ■        ■    ■        ■        ■\n");//10
	Sleep(100);gotoxy(x,y+10);printf("  ■      ■■    ■    ■        ■    ■■  \n");//11
	while(1){
		if(kbhit())break;
		Sleep(800);
		gotoxy(x+13,y+12);printf("PRESS ANY KEY!");
		if(kbhit())break;
		Sleep(800);
		gotoxy(x+13,y+12);printf("              ");
	}
	CLEAR;
	GameScreen();
}

void new_block(int x,int y) {  // 블럭 생성 함수 
	int i,j;
	for(i=0; i<4; i++) {
		for(j=0; j<4; j++) {
			if(blocks[block_type][block_turn][i][j]==1) {
				gotoxy(x+i,y+j);
				block_x=x+i;          /*----- 블럭 위치 저장 -----*/ 
				block_y=y+j; 
				colors_();
				printf("▣");
				ORIGINAL;
			}
			if(blocks[block_type][block_turn][i][j]==0) {
				gotoxy(x+i,y+j);
				printf("  ");
			}
		}
	}
}

int check_crash (void) { // 충돌 할시 1, 아닐시 0을 반환. (block_height 값을 0으로 지정) 
	int i,j;
	 for(i=0; i<4; i++) {
		for(j=0; j<4; j++) {
			if(blocks[block_type][block_turn][i][j]==1&&block_y==WALL_Y_MAX-1) {
				block_height=0;
				stop=1;
			}
		}
	}
	if(stop==1){
		for(i=0; i<12; i++) {
			gotoxy(i+5,23);
			printf("▩");//5~15,23(6~14,23)
		}
	}
}

void colors_(void){
	switch (block_type){
		case 0:  YELLOW;break;
		case 1: SKY_BLUE;break;
		case 2: HIGH_GREEN;break;
		case 3: RED;break;
		case 4: BLUE;break;
		case 5: BLOOD;break;
		case 6: PLUM;break;
	}
		

}

void block_move (void) {
	
}
