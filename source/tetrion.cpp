#include "../header/tetrion.h"

Tetrion::Tetrion(
	Buffer *buffer = NULL,
	Measure measure = {12, 26},
	Coordinate coordinate = {0, 0}
) : Imaginary(buffer, measure, coordinate) {
	const int CEILING = 0;
	const int FLOOR = measure.height - 1;
	const int LEFT = 0;
	const int RIGHT = measure->width - 1;

	int pos;

	// TODO: initialize data field

	for(int i = CEILING; i <= FLOOR; i++) {
		for(int j = LEFT; j <= RIGHT; j++) {
			pos = (i + position.x) * size.width + (j + position.y);
			if(i == CEILING || i == FLOOR) {
				playfield->sketch(pos, true);

			} else {
				if(j == LEFT || j == RIGHT) {
					playfield->sketch(pos, true);
				} else {
					playfield->sketch(pos, false);
				}
			}
		}
	}
}
