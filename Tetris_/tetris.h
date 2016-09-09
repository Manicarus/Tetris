#pragma once

//#include "tetromino.h"
#include "bucket.h"
#include "cursor.h"

class Tetris {
public:
	void draw();
	
private:
//	Tetromino tetromino;
	Bucket bucket;
	Cursor cursor;
};
