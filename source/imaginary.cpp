#include "../header/imaginary.h"

void Imaginary::sketch() {
	int pos;
	int dataSize = getSize();

	try {
		if(canvas == NULL) {
			throw "Null Pointer Exception: No Playfield Initialized";
		}
		for(int i = 0; i < dataSize; i++) {
			pos = (position.x + i % size.width) 
				+ (position.y + i / size.width) * playfield->getWidth();
			playfield->setData(pos, data[i]);
		}
	} catch (char const *errStr) {
		system("cls");
		std::cout << errStr << std::endl;
		exit(0);
	}
}

