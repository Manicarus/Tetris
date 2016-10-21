#ifndef __TETRIS_COMPONENT_HPP__
#define __TETRIS_COMPONENT_HPP__

#include "buffer.hpp"
#include "fundamentals.hpp"

class TetrisComponent {
protected:
	Coordinate position;
	Dimension container;
	dataType *data;
	
public:
	TetrisComponent(Coordinate, Dimension);
	~TetrisComponent();
	
	int getSize();
	int getWidth();
	int getX();
	int getY();
	
	dataType getDataAt(int);
	virtual void update();
};

#endif
