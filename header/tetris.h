#ifndef __TETRIS_H__
#define __TETRIS_H__

#include "console.h"
#include <conio.h>
#include "game.h"
#include "tetromino.h"
#include "tetrion.h"
#include "stack.h"
#include "playfield.h"


class Tetris : Game{
public:
	Tetris();
	~Tetris();
	bool isArrowInput(int keyboardInput);
	void update();
	void render();

private:
	Tetromino *tetromino;
	Tetrion *tetrion;
	Stack *stack;
	Console *console;
};

#endif

// When you have trouble thinking of good names for objects,
// refer to glossary of the game.
// Reference: http://tetris.wikia.com/wiki/Glossary
