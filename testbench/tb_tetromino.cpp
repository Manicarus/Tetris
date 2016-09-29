#include "../header/tetromino.h"
#include "../header/buffer.h"
#include <iostream>

int main() {
	Buffer playfield({12, 26});
	Tetromino tetromino(&playfield);

	tetromino.sketch();

	for(int i = 0; i < 26; i++) {
		for(int j = 0; j < 12; j++) {
			std::cout << (playfield.back[i * 12 + j] ? "O" : "X");
		}
		std::cout << std::endl;
	}

	return 0;
}
