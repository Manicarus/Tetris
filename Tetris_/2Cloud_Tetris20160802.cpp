//코드가 더러워져서 다시짭니다...

/*
walls=1
void(empty)=0
blocks(move)=1
blocks(set)=2
*/

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

int blocks[7][4][4][4]= {
	{{0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0},{0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0},{0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0},{0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0}},
	{{0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0},{0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0},{0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0},{0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0}},
	{{0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0},{0,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0},{0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0},{0,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0}},
	{{0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0},{0,0,0,0,1,0,0,0,1,1,0,0,0,1,0,0},{0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0},{0,0,0,0,1,0,0,0,1,1,0,0,0,1,0,0}},
	{{0,0,0,0,0,0,1,0,1,1,1,0,0,0,0,0},{0,0,0,0,1,1,0,0,0,1,0,0,0,1,0,0},{0,0,0,0,0,0,0,0,1,1,1,0,1,0,0,0},{0,0,0,0,0,1,0,0,0,1,0,0,0,1,1,0}},
	{{0,0,0,0,1,0,0,0,1,1,1,0,0,0,0,0},{0,0,0,0,0,1,0,0,0,1,0,0,1,1,0,0},{0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,0},{0,0,0,0,0,1,1,0,0,1,0,0,0,1,0,0}},
	{{0,0,0,0,0,1,0,0,1,1,1,0,0,0,0,0},{0,0,0,0,0,1,0,0,0,1,1,0,0,1,0,0},{0,0,0,0,0,0,0,0,1,1,1,0,0,1,0,0},{0,0,0,0,0,1,0,0,1,1,0,0,0,1,0,0}}
};

int walls[25][12]= { //(-1)
	{-1,0,0,0,0,0,0,0,0,0,0,-1},
	{-1,0,0,0,0,0,0,0,0,0,0,-1},
	{-1,0,0,0,0,0,0,0,0,0,0,-1},
	{-1,0,0,0,0,0,0,0,0,0,0,-1},
	{-1,0,0,0,0,0,0,0,0,0,0,-1},
	{-1,0,0,0,0,0,0,0,0,0,0,-1},
	{-1,0,0,0,0,0,0,0,0,0,0,-1},
	{-1,0,0,0,0,0,0,0,0,0,0,-1},
	{-1,0,0,0,0,0,0,0,0,0,0,-1},
	{-1,0,0,0,0,0,0,0,0,0,0,-1},
	{-1,0,0,0,0,0,0,0,0,0,0,-1},
	{-1,0,0,0,0,0,0,0,0,0,0,-1},
	{-1,0,0,0,0,0,0,0,0,0,0,-1},
	{-1,0,0,0,0,0,0,0,0,0,0,-1},
	{-1,0,0,0,0,0,0,0,0,0,0,-1},
	{-1,0,0,0,0,0,0,0,0,0,0,-1},
	{-1,0,0,0,0,0,0,0,0,0,0,-1},
	{-1,0,0,0,0,0,0,0,0,0,0,-1},
	{-1,0,0,0,0,0,0,0,0,0,0,-1},
	{-1,0,0,0,0,0,0,0,0,0,0,-1},
	{-1,0,0,0,0,0,0,0,0,0,0,-1},
	{-1,0,0,0,0,0,0,0,0,0,0,-1},
	{-1,0,0,0,0,0,0,0,0,0,0,-1},
	{-1,0,0,0,0,0,0,0,0,0,0,-1},
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}
};
int original_walls[25][12]={0};
int walls_cpy[25][12]= {0};

int block_type=0;
int block_turn=0;
int block_x=1;
int block_y=0; // high
int block_cx;
int block_cy;
int next_block=NULL;

int XxX=0;
int YyY=0;

int first__=1;







/*                                            /*------------------------------ declare the functions ------------------------------*/
void spawn_block(int x, int y);           
void create_walls(void);
int check_crash(void);

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

void gotoxy(int x,int y){
	COORD CursorPosition={x*2,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),CursorPosition);
}



int main(){                               /*------------------------------ main function ------------------------------*/
	//12,0
	int i;
	
	setcursortype(NOCURSOR);
	srand((unsigned)time(NULL));
	create_walls();
	for(;;){
		
		for(i=0;i<10;i++){
			
		}
		spawn_block(block_x,block_y);
		
		create_walls();
		Sleep(500);block_y+=1;
	}
	
	
	getch();
}                                         /*------------------------------ main function ------------------------------*/



void spawn_block(int x,int y){
	int i,j;//i=x,j=y
	
	for(i=0;i<4;i++){
	
		for(j=0;j<4;j++){
			
			if(blocks[block_type][block_turn][i][j]==1){ // 블럭값은 가로 j 세로 i 
				//gotoxy(x+j,y+i);printf("▣");            // 좌표값은 가로가 x므로 j열이 먼저 출력되어 값을 이렇게 정함 
				walls[y+i][x+j]=0;
				walls[y+i][x+j]=1;
				block_cx=x+j;
				block_cy=y+i;
				check_crash();
				
			}else if(blocks[block_type][block_turn][i][j]==0){
				//walls[y+i][x+j]=0;
				walls[y+i][x+j]=0;
			}
			gotoxy(0,0);printf("y : %-2d",block_cy);gotoxy(0,1);printf("x : %-2d",block_cx);
			//Sleep(200);
		}
		
	}
}

void create_walls(void){
	int x,y;
	
	for(x=0;x<12;x++){
		
		for(y=0;y<25;y++){
			
			if(first__==1||walls[y][x]!=walls_cpy[y][x]){
				
				if(walls[y][x]==-1){
					
					gotoxy(x+8,y);printf("▩"); 
					
				}else if(walls[y][x]==1){
					
				
					gotoxy(x+8,y);printf("▣");
					
				}else if(walls[y][x]==0){
					
					gotoxy(x+8,y);printf("  ");
					
				}
				
			}
			
			walls_cpy[y][x]=walls[y][x];
		}
	}
	first__=0;
}

int check_crash(void){
	int i,j;
	
	for(i=0;i<4;i++){
		
		for(j=0;j<4;j++){
			
			if(blocks[block_type][block_turn][i][j]&&block_cy>=24){ // if it is equal to one
				
				
				
			}
		}
	}
	
}
