//�ڵ尡 ���������� �ٽ�¬�ϴ�...

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
#define BLACK         SetConsoleTextAttribute(COL,0x0000); //������ 
#define DARK_BLUE     SetConsoleTextAttribute(COL,0x0001); //�Ķ��� 
#define GREEN         SetConsoleTextAttribute(COL,0x0002); //��� 
#define BLUE_GREEN    SetConsoleTextAttribute(COL,0x0003); //û��� 
#define BLOOD         SetConsoleTextAttribute(COL,0x0004); //�˺����� 
#define PURPLE        SetConsoleTextAttribute(COL,0x0005); //����� 
#define GOLE          SetConsoleTextAttribute(COL,0x0006); //�ݻ� �� 
#define ORIGINAL      SetConsoleTextAttribute(COL,0x0007); //����ȸ�� 
#define GRAY          SetConsoleTextAttribute(COL,0x0008); //ȸ�� 
#define BLUE          SetConsoleTextAttribute(COL,0x0009); //�Ķ��� 
#define HIGH_GREEN    SetConsoleTextAttribute(COL,0x000a); //���λ� 
#define SKY_BLUE      SetConsoleTextAttribute(COL,0x000b); //�ϴû� 
#define RED           SetConsoleTextAttribute(COL,0x000c); //������ 
#define PLUM          SetConsoleTextAttribute(COL,0x000d); //���ֻ� 
#define YELLOW        SetConsoleTextAttribute(COL,0x000e); //��� 

#define LEFT 75 // Go Left
#define RIGHT 77 // Go Right
#define UP 72 // Turn
#define DOWN 80 // Quick Drop
#define MOVEAR 224 // Ű���� ȭ��ǥ �� 'MoveArrow'
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

typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE; //Ŀ���Ⱥ��̰��ϴ� �Լ��� ���Ǵ� ������

void setcursortype(CURSOR_TYPE c) { //Ŀ�� �Ⱥ��̰� �ϴ� �Լ�
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



int main(){
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
}



void spawn_block(int x,int y){
	int i,j;//i=x,j=y
	
	for(i=0;i<4;i++){
	
		for(j=0;j<4;j++){
			
			if(blocks[block_type][block_turn][i][j]==1){ // ������ ���� j ���� i 
				//gotoxy(x+j,y+i);printf("��");            // ��ǥ���� ���ΰ� x�Ƿ� j���� ���� ��µǾ� ���� �̷��� ���� 
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
					
					gotoxy(x+8,y);printf("��"); 
					
				}else if(walls[y][x]==1){
					
				
					gotoxy(x+8,y);printf("��");
					
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
