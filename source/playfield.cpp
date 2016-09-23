#include "playfield.h"

void Playfield::flipBuffer() {
	bool *tmpBuffer;
	tmpBuffer = frontBuffer;
	frontBuffer = backBuffer;
	backBuffer = tmpBuffer;
}
