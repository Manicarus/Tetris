#include "../header/tetrion.h"

Tetrion::Tetrion(Playfield *playfield) : Component(playfield) {
	const int CEILING = 0;
	const int FLOOR = Component::canvas->height - 1;
	// const int FLOOR = Component::canvas.height - 1;
	const int LEFT = 0;
	const int RIGHT = Component::canvas->width - 1;

	int pos;

	for(int i = CEILING; i <= FLOOR; i++) {
		for(int j = LEFT; j <= RIGHT; j++) {
			pos = (i + Component::x) * Component::canvas->width + (j + Component::y);
			if(i == CEILING || i == FLOOR) {
				Component::canvas->setSketch(pos, true);
			} else {
				if(j == LEFT || j == RIGHT) {
					Component::canvas->setSketch(pos, true);
				} else {
					Component::canvas->setSketch(pos, false);
				}
			}
		}
	}
}
