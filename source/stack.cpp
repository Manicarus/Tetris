#include <iostream>

#include "stack.h"
#include <windows.h>

#define	O	true
#define	X	false

Stack::Stack() {
	x = 2;
	y = 2;
	
	for(int rowIndex = CEILING; rowIndex < ROW_NUM; rowIndex++) {
		layer[rowIndex] = new bool [COL_NUM];
		
		if(rowIndex == FLOOR || rowIndex == CEILING) {
			for(int colIndex = 0; colIndex < COL_NUM; colIndex++) {
				layer[rowIndex][colIndex] = O;
			}
		} else {
			layer[rowIndex][0] = O;
			for(int colIndex = 1; colIndex < RIGHTMOST_COL; colIndex++) {
				layer[rowIndex][colIndex] = X;
			}
			layer[rowIndex][RIGHTMOST_COL] = O;
		}
	}
}

Stack::~Stack() {
	for(int rowIndex = CEILING; rowIndex < ROW_NUM; rowIndex++) {
		delete layer[rowIndex];
	}
}

void Stack::clear() {
	for(int rowIndex = CEILING; rowIndex < ROW_NUM; rowIndex++) {
		if(isLayerFull(rowIndex)) {
			clearLayer(rowIndex);
		}
	}
}

void Stack::draw() {
	for(int rowIndex = CEILING; rowIndex < ROW_NUM; rowIndex++) {
		drawLayer(rowIndex);
	}
}

void Stack::drawLayer(int row) {
	
	for(int colIndex = 0; colIndex < COL_NUM; colIndex++) {
		if(layer[row][colIndex]) {
			COORD cursorPos = {2 * (x + colIndex), y + row};
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPos);
			std::cout << "бс" << std::endl;
		}
	}
}

void Stack::clearLayer(int row) {
	int upperRowIndex;
	
	delete layer[row];
	
	for(int rowIndex = row; rowIndex > 0; rowIndex--) {
		upperRowIndex = rowIndex - 1;
		layer[rowIndex] = layer[upperRowIndex];
	}
	
	layer[CEILING] = new bool [COL_NUM];
	
	layer[CEILING][0] = O;	
	for(int colIndex = 1; colIndex < RIGHTMOST_COL; colIndex++) {
		layer[CEILING][colIndex] = X;
	}		
	layer[CEILING][RIGHTMOST_COL] = O;
}

bool Stack::isLayerFull(int row) {
	for(int colIndex = 0; colIndex < COL_NUM; colIndex++) {
		if(layer[row][colIndex]) {
			return false;
		}
	}
	
	return true;
}
