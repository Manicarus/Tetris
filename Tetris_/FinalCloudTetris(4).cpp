/*
walls=-1
void(empty)=0
blocks(move)=1
blocks(set)=2
*/

//블럭버그해
//잔버그 주의


#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>

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
	{{0,0,0,0,0,0,1,0,0,1,1,1,0,0,0,0},{0,0,0,0,0,0,1,0,0,0,1,1,0,0,1,0},{0,0,0,0,0,0,0,0,0,1,1,1,0,0,1,0},{0,0,0,0,0,0,1,0,0,1,1,0,0,0,1,0}}, 
	{{0,0,0,0,1,0,0,0,1,1,1,0,0,0,0,0},{0,0,0,0,0,1,0,0,0,1,0,0,1,1,0,0},{0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,0},{0,0,0,0,0,1,1,0,0,1,0,0,0,1,0,0}},
	{{0,0,0,0,0,0,1,0,1,1,1,0,0,0,0,0},{0,0,0,0,1,1,0,0,0,1,0,0,0,1,0,0},{0,0,0,0,0,0,0,0,1,1,1,0,1,0,0,0},{0,0,0,0,0,1,0,0,0,1,0,0,0,1,1,0}},
	{{0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0},{0,0,0,0,1,0,0,0,1,1,0,0,0,1,0,0},{0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0},{0,0,0,0,1,0,0,0,1,1,0,0,0,1,0,0}},
	{{0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0},{0,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0},{0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0},{0,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0}},
	{{0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0},{0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0},{0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0},{0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0}},
	{{0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0},{0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0},{0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0},{0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0}}

};

int walls[25][12]= { //(-1) // y x
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
int cpy_walls[25][12];
int line_walls[25][12];

int wall_x=5;
int wall_y;

int b_turn;
int b_type;
int bb_type;
int b_x=4;//배열상
int b_y=-2;
int enable_move_left=1;
int enable_move_right=1;
int enable_move_down=1;
int enable_move_up=1;
int new_b=1;
int asd=100;
int block_speed=500;



void gotoxy(int x,int y) {
	COORD CursorPosition= {x*2,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),CursorPosition);
}

typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;
void setcursortype(CURSOR_TYPE c) {
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



void create_world();
void ModTick();
void move_block(int mvoe);
void create_block();
void check_move();
void check_crash();
void check_wall();
void new_block();
void set_block();
void colors_(int dir);
void check_line();
void destroy_line(int i);


int main() {                                                    /*------------------------------main function------------------------------*/
	setcursortype(NOCURSOR);
	create_world();
	int i;
	srand((unsigned)time(NULL));
	for(;;) {
		ModTick();
		
		check_wall();//checck_crash
		set_block();
		new_block();
		check_move();//move_block();
		check_crash();
		i++;
		Sleep(1);
		if (i>block_speed) {
			i=0;
			move_block(DOWN);
		}
		gotoxy(0,0);
		printf("%3d",b_x);
		gotoxy(0,1);
		printf("%3d",b_y);
		gotoxy(0,3);
		printf("%3d",b_type);
		check_line();
	}


	gotoxy(0,0);
	getch();
}                                                               /*------------------------------main function------------------------------*/


void create_world() {
	int i,j;
	for(i=0; i<25; i++) {
		for(j=0; j<12; j++) {

			if(walls[i][j]==-1) {
				gotoxy(wall_x+j,wall_y+i);
				printf("▩");
			}else if(!walls[i][j]){
				gotoxy(wall_x+j,wall_y+i);
				printf("  ");
			}
		}
	}
}

void check_move() {
	int k;
	if(kbhit()) {
		k=getch();
		if(k==224){
			while(k==224)break;
			k=getch();
			move_block(k);//gotoxy(0,0);printf("%d",k);
		}else if(k==32){                              /*-------------SPACE BAR-------------*/
			
		}else{}
	}
}

void set_block(){
	int i,j,l;
	if(!enable_move_down){
		for(l=0;l<block_speed;l++){
			Sleep(1);
			check_move();
		}new_b=1;
		for(i=0;i<25;i++){
			for(j=0;j<12;j++){
				if(walls[i][j]==1){
					walls[i][j]=2;
				}
			}
		}
	}
}

void check_wall(){
	int i,j,s,d;
	for(j=0;j<24;j++){
		if(walls[j][1]==1){
			enable_move_left=0;
			enable_move_up=0;
		}else if(walls[j][10]==1){
			enable_move_right=0;
			enable_move_up=0;
		}
	}
	for(j=0;j<12;j++){
		if(walls[23][j]==1){
			enable_move_down=0;
			
			asd=0;
		}
	}
	s=0;
	d=0;
	for(j=0;j<24;j++){
		s=s+walls[j][1];
		d=d+walls[j][10];
	}
	if(s==0){enable_move_left=1;enable_move_up=1;}
	if(d==0){enable_move_right=1;enable_move_up=1;}
}

void check_line(){
	int i, j, l;
	
	for ( i = 0 ; i < 24 ; i ++ ) {
		for ( j = 1 ; j < 11 ; j ++) {
			if (walls[i][j] != 2) break;
			if ( j == 10 )destroy_line(i);
		}
	}
	
}

void destroy_line(int i) {
	int j, x, y;
	for ( j = 1 ; j < 11 ; j ++ ) {
		walls[i][j]=0;
	}
	
	for ( y = 0 ; y < i ; y ++ ) {
		for ( x = 1 ; x < 11 ; x ++ ) {
			line_walls[y+1][x] = walls[y][x];
		}
	}
	for ( y = 1 ; y < 24 ; y ++ ) {
		for ( x = 1 ; x < 11 ; x ++ ) {
			walls[y][x]=line_walls[y][x];
		}
	}
}

void new_block(){
	if(new_b){
		b_turn=0;
		bb_type=b_type;
		b_type=rand()%7;
		b_x=4;
		b_y=-2;
		enable_move_down=1;
		enable_move_left=1;
		enable_move_right=1;
		enable_move_up=1;
		new_b=0;
	}
}

void check_crash() { //b_x 1~10 b_y 0~23     /*-------------------(block's crash)test------------------*/
	int i,j;
	
	for ( i = 0 ; i < 25 ; i ++ ) {
		for ( j = 0 ; j < 12 ; j ++ ) {
			if ( walls[i][j] == 1 ) {
				if(walls[i][j-1]==2) {enable_move_left = 0; enable_move_up=0;}
				if(walls[i][j-1]==0) {enable_move_left = 1; enable_move_up=1;}
				
				if(walls[i][j+1]==2) {enable_move_right = 0; enable_move_up=0;}
				if(walls[i][j+1]==0) {enable_move_right = 1; enable_move_up=1;}
				
				if(walls[i+1][j]==2) {enable_move_down = 0; enable_move_up=0;}
				if(walls[i+1][j]==0) {enable_move_down = 1; enable_move_up=1;}
				
				
				
			}
		}
	}	
}

void ModTick() {
	int x,y;

	for(y=0; y<25; y++) {
		for(x=0; x<12; x++) {
			if(walls[y][x]!=cpy_walls[y][x]) {

				if (walls[y][x]==0) {

					gotoxy(wall_x+x, wall_y+y);
					printf("  ");

				} else if (walls[y][x]==-1) {

					gotoxy(wall_x+x, wall_y+y);
					printf("▩");

				} else if (walls[y][x]==1) {

					gotoxy(wall_x+x, wall_y+y);
					colors_(b_type);
					printf("▣");

				} if (walls[y][x]==2) {

					gotoxy(wall_x+x, wall_y+y);
					colors_(bb_type);
					printf("■");

				}
			}

		}
	}
	for(y=0; y<25; y++) {
		for(x=0; x<12; x++) {
			cpy_walls[y][x]=walls[y][x];
		}
	}
}




void move_block(int move) {
	int i,j;

	switch(move) {
		case LEFT:
			if(enable_move_left) {
				for(i=0; i<4; i++) {
					for(j=0; j<4; j++) {
						if (blocks[b_type][b_turn][i][j]==1) {
							walls[b_y+j][b_x+i]=0;
						}
					}
				}
				for(i=0; i<4; i++) {
					for(j=0; j<4; j++) {
						if (blocks[b_type][b_turn][i][j]==1) {
							walls[b_y+j][b_x+i-1]=1;
						}
					}
				}
				b_x--;
			}
			break;

		case RIGHT:
			if(enable_move_right) {
				for(i=0; i<4; i++) {
					for(j=0; j<4; j++) {
						if (blocks[b_type][b_turn][i][j]==1) {
							walls[b_y+j][b_x+i]=0;
						}
					}
				}
				for(i=0; i<4; i++) {
					for(j=0; j<4; j++) {
						if (blocks[b_type][b_turn][i][j]==1) {
							walls[b_y+j][b_x+i+1]=1;
						}
					}
				}
				b_x++;
			}
			break;

		case DOWN://dorp
			if(enable_move_down) {
				for(i=0; i<4; i++) {
					for(j=0; j<4; j++) {
						if (blocks[b_type][b_turn][i][j]==1) {
							walls[b_y+j][b_x+i]=0;
						}
					}
				}
				for(i=0; i<4; i++) {
					for(j=0; j<4; j++) {
						if (blocks[b_type][b_turn][i][j]==1) {
							walls[b_y+j+1][b_x+i]=1;
						}
					}
				}
				b_y++;
			}
			break;

		case UP://turn
			if(enable_move_up==1) {
				for(i=0; i<4; i++) {
					for(j=0; j<4; j++) {
						if (blocks[b_type][b_turn][i][j]==1) {
							walls[b_y+j][b_x+i]=0;
						}
					}
				}
				b_turn=(b_turn+1)%4;
				for(i=0; i<4; i++) {
					for(j=0; j<4; j++) {
						if (blocks[b_type][b_turn][i][j]==1) {
							walls[b_y+j][b_x+i]=1;
						}
					}
				}
			}
			break;
	}
}

void colors_(int dir) {
	switch (dir) {
		case 0:
			YELLOW;
			break;
		case 1:
			SKY_BLUE;
			break;
		case 2:
			HIGH_GREEN;
			break;
		case 3:
			RED;
			break;
		case 4:
			BLUE;
			break;
		case 5:
			BLOOD;
			break;
		case 6:
			PLUM;
			break;
	}


}







