#include "../header/tetrion.hpp"

Tetrion::Tetrion(Coordinate coordinate)
 : TetrisComponent(coordinate, Dimension(12, 26)) {
	const int CEILING = 0;
	const int FLOOR = container.getHeight() - 1;
	const int LEFT = 0;
	const int RIGHT = container.getWidth() - 1;

	int dataIndex;

	for(int i = CEILING; i <= FLOOR; i++) {
		for(int j = LEFT; j <= RIGHT; j++) {
			dataIndex = (i + position.getY()) * container.getWidth() + (j + position.getX());
			if(i == CEILING || i == FLOOR) {
				data[dataIndex] = BLOCK;

			} else {
				if(j == LEFT || j == RIGHT) {
					data[dataIndex] = BLOCK;
				} else {
					data[dataIndex] = FIELD;
				}
			}
		}
	}
}

void Tetrion::update() {
	
}
