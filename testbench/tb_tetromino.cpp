#include "../header/tetromino.hpp"
#include "../header/buffer.hpp"
#include <iostream>

int main() {
	TetrisComponent *tetromino = new Tetromino(Coordinate(0, 0));

	tetromino->sketch();
	tetromino->getCanvas()->print();

	return 0;
}
