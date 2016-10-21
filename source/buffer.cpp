#include "../header/buffer.hpp"
#include <iostream>
#include <cstdlib>

SingleBuffer::SingleBuffer(Dimension dimension) {	
	data = new dataType[dimension.getSize()];
	for(int i = 0; i < dimension.getSize(); i++) {
		*(data + i) = EMPTY;
	}
}

SingleBuffer::~SingleBuffer() {
	if(data != NULL) {
		delete data;
	}
}

void SingleBuffer::setDataAt(int dataIndex, dataType newData) {
	*(data + dataIndex) = newData;
}

dataType SingleBuffer::getDataAt(int dataIndex) {
	return *(data + dataIndex);
}

void SingleBuffer::clear(Dimension dimension) {
	if(data != NULL) {
		delete data;
	}
	
	data  = new dataType[dimension.getSize()];
	for(int i = 0; i < dimension.getSize(); i++) {
		*(data + i) = false;
	}
}

DoubleBuffer::DoubleBuffer(Dimension dimension) {
	front = new SingleBuffer(dimension);
	back = new SingleBuffer(dimension);
}

bool DoubleBuffer::isUnchanged(int dataIndex) {
	return front->getDataAt(dataIndex) == back->getDataAt(dataIndex);
}

void DoubleBuffer::flip() {
	SingleBuffer *tmpBuffer;
	tmpBuffer = front;
	front = back;
	back = tmpBuffer;
}

