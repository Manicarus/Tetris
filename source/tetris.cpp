#include "../header/tetris.h"
#include <iostream>
#include <cstdlib>

Tetris::Tetris() {

}

void Tetris::render() {
	// tetromino.setVisibility(true);
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
