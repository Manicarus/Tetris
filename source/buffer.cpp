#include "../header/buffer.h"
#include <cstdlib>

Buffer::Buffer(
	Measure measure = {0, 0},
	Coordinate coordinate = {0, 0}
) : Component(measure, coordinate) {
	data = new bool[2 *getSize()];

	front = (bool *)data;
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
		delete (bool *)data;
	}
}

int Buffer::getSize(){
	return size.width * size.height;
}

int Buffer::getWidth() {
	return size.width;
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
