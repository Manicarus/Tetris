#include "../header/tetris_component.hpp"
#include <cstdlib>
#include <iostream>

TetrisComponent::TetrisComponent(Coordinate coordinate, Dimension dimension) 
: position(coordinate), container(dimension) {
	data = new dataType[container.getSize()];

	for(int i = 0; i < container.getSize(); i++) {
		data[i] = false;
	}
}

TetrisComponent::~TetrisComponent() {
	if(data != NULL) {
		delete data;
	}
}

int TetrisComponent::getX() {
	return position.getX();
}

int TetrisComponent::getY() {
	return position.getY();
}

int TetrisComponent::getWidth() {
	return container.getWidth();
}

int TetrisComponent::getSize() {
	return container.getSize();
}

dataType TetrisComponent::getDataAt(int dataIndex) {
	return *(data + dataIndex);
}

void TetrisComponent:update() {};
