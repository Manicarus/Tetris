#include "../header/tetris.h"
#include <iostream>
#include <cstdlib>

Tetris::Tetris(Console *console) {
	this->console = console;
	tetromino = new Tetromino(console.buffer);
	tetrion = new Tetrion(console.buffer);
	stack = new Stack(console.buffer);
}

Tetris::~Tetris() {
	tetromino.~Tetromino();
	delete tetromino;

	tetrion.~Tetrion();
	delete tetrion;

	stack.~Stack();
	delete stack;
}

void Tetris::render() {
	// tetromino.setVisibility(true);
	tetromino.sketch();
	tetrion.sketch();
	stack.sketch();
	console.render();
}

void Tetris::update() {

	int keyboardInput, arrowInput;
	if(kbhit()) {
		keyboardInput = getch();
		if(isArrowInput(keyboardInput)) {
			arrowInput = getch();

		    tetromino.setVisibility(false);
			tetromino.move((Direction)(arrowInput));

			if(tetromino.collidesWith(playfield)) {
				tetromino.move(tetromino.revertDir((Direction)(arrowInput)));
			}

		} else {
			switch(keyboardInput) {
				case ' ':
					while(!tetromino.collidesWith(playfield)) {
						tetromino.setVisibility(false);
						tetromino.move(DOWN);
					}
					tetromino.move(UP);
					break;
				case ESC:
					system("cls");
					exit(0);
			}
		}
	}
}

bool Tetris::isArrowInput(int keyboardInput) {
	return (keyboardInput == 0xE0 || keyboardInput == 0);
}
