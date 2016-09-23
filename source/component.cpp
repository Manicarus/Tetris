#include "component.h"

Componenet::Component() {
	x = 0; y = 0;
	w = 0; h = 0;
	canvas = nullptr;
}

Component::Component(Playfield *playfield) {
	Component();
	canvas = playfield;
}

void Component::sketch() {
	int pos;
	int dataSize = w * h;
	
	try {
		if(canvas == nullptr) {
			throw "No canvas initialized";
		}
		
		for(int i = 0; i < dataSize; i++) {
			pos = (x + i % w) + (y + i / w) * w;
			canvas[pos] = data[i];
		}
	} catch (char *errStr) {
		system("cls");
		std::cout << errStr << std::endl;
		exit(0);
	}
}
