#include "../header/imaginary.h"
#include <cstdlib>
#include <iostream>

Imaginary::Imaginary(
	Buffer *buffer = NULL,
	Measure measure = {0, 0},
	Coordinate coordinate = {0, 0}
) : Component(measure, coordinate) {
	playfield = buffer;
}

void Imaginary::sketch() {
	int pos;
	int dataSize = getSize();

	try {
		if(playfield == NULL) {
			throw "Null Pointer Exception: No Playfield Initialized";
		}
		for(int i = 0; i < dataSize; i++) {
			pos = (position.x + i % size.width)
				+ (position.y + i / size.width) * playfield->getWidth();
			playfield->setData(pos, ((bool *)data + i));
		}
	} catch (char const *errStr) {
		system("cls");
		std::cout << errStr << std::endl;
		exit(0);
	}
}
