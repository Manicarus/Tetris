#ifndef __BUFFER_HPP__
#define __BUFFER_HPP__

#include "fundamentals.hpp"

class SingleBuffer {
private:
	dataType *data;

public:
	SingleBuffer(Dimension);
	~SingleBuffer();
	
	void clear(Dimension);
	void setDataAt(int, dataType);
	dataType getDataAt(int);
};

class DoubleBuffer {
private:
public:
	DoubleBuffer(Dimension);
		
	SingleBuffer *front;
	SingleBuffer *back;
	
	void flip();
	bool isUnchanged(int dataIndex);
};

#endif
