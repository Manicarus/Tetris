#ifndef __STACK_H__
#define __STACK_H__

#define ROW_NUM			26
#define COL_NUM			12

#define CEILING			0
#define FLOOR		(ROW_NUM - 1)

#define RIGHTMOST_COL	(COL_NUM - 1)

#include <conio.h>
#include "component.h"

class Stack : Imaginary {
public:
	Stack();
	~Stack();

    void clear();
    void draw();
    bool *layer[ROW_NUM];

private:

	void clearLayer(int row);
	bool isLayerFull(int row);
	void drawLayer(int row);
};

#endif
