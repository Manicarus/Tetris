#include "../header/buffer.h"
#include <cstdlib>

Buffer::Buffer(
	Coordinate coordinate = {0, 0},
	Dimension dimension = {0, 0}
) : Component(coordinate, dimension) {
	data = new bool[2 *getSize()];
	
	front = data
	for(int i = 0; i < getSize(); i++) {
		*(front + i) = false;
	}
	
	back  = front + getSize();
	for(int i = 0; i < getSize(); i++) {
		*(back + i) = false;
	}
}

Buffer::~Buffer() {
	if(data != NULL) {
		delete data;
	}
}

int Buffer::getSize(){
	return width * height;
}

int Buffer::getWidth() {
	return width;
}

void Buffer::setData(int pos, bool data) {
	*(back + pos) = data;
}

void Buffer::flip() {
	bool *tmpBuffer;
	tmpBuffer = front;
	front = back;
	back = tmpBuffer;
}


