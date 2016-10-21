#ifndef __STACK_HPP__
#define __STACK_HPP__

#define ROW_NUM			26
#define COL_NUM			12

#define CEILING			0
#define FLOOR		(ROW_NUM - 1)

#define RIGHTMOST_COL	(COL_NUM - 1)

#include "Component.hpp"

class Stack : Component {
public:
	Stack(Size);
	~Stack();

    void clear();
    bool *layer[ROW_NUM];

private:
	bool *tetrion;

	bool isLayerFull(int row);
	void drawLayer(int row);
};

#endif
