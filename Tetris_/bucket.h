#pragma once

#define ROW_NUM			25
#define COL_NUM			12

#define TOP_ROW			0
#define BOTTOM_ROW		(ROW_NUM - 1)

#define RIGHTMOST_COL	(COL_NUM - 1)

#include "cursor.h"

class Bucket {
public:
	Bucket();
	~Bucket();
	
    void clear();
    void draw(Cursor cursor);
    
private:
	bool *layer[ROW_NUM];
	
	void clearLayer(int row);
	bool isLayerFull(int row);
	void drawLayer(int row, Cursor cursor);
};
