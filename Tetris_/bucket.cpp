#include <iostream>

#include "bucket.h"
#include "cursor.h"

#define	O	true
#define	X	false

Bucket::Bucket() {
	for(int rowIndex = TOP_ROW; rowIndex < ROW_NUM; rowIndex++) {
		layer[rowIndex] = new bool [COL_NUM];
		
		if(rowIndex == BOTTOM_ROW) {
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

Bucket::~Bucket() {
	for(int rowIndex = TOP_ROW; rowIndex < ROW_NUM; rowIndex++) {
		delete layer[rowIndex];
	}
}

void Bucket::clear() {
	for(int rowIndex = TOP_ROW; rowIndex < ROW_NUM; rowIndex++) {
		if(isLayerFull(rowIndex)) {
			clearLayer(rowIndex);
		}
	}
}

void Bucket::draw(Cursor cursor) {
	for(int rowIndex = TOP_ROW; rowIndex < ROW_NUM; rowIndex++) {
		drawLayer(rowIndex, cursor);
	}
}

void Bucket::drawLayer(int row, Cursor cursor) {
	for(int colIndex = 0; colIndex < COL_NUM; colIndex++) {
		cursor.move(colIndex, row);
		if(layer[row][colIndex] == O) {
			std::cout << "¢Ì" << std::endl;
		} else {
			std::cout << "  " << std::endl;
		}
	}
}

void Bucket::clearLayer(int row) {
	int upperRowIndex;
	
	delete layer[row];
	
	for(int rowIndex = row; rowIndex > 0; rowIndex--) {
		upperRowIndex = rowIndex - 1;
		layer[rowIndex] = layer[upperRowIndex];
	}
	
	layer[TOP_ROW] = new bool [COL_NUM];
	
	layer[TOP_ROW][0] = O;	
	for(int colIndex = 1; colIndex < RIGHTMOST_COL; colIndex++) {
		layer[TOP_ROW][colIndex] = X;
	}		
	layer[TOP_ROW][RIGHTMOST_COL] = O;
}

bool Bucket::isLayerFull(int row) {
	for(int colIndex = 0; colIndex < COL_NUM; colIndex++) {
		if(layer[row][colIndex]) {
			return false;
		}
	}
	
	return true;
}
