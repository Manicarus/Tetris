#pragma once
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
	bool isArrowInput(int keyboardInput);
	
private:
	Tetromino tetromino;
	Tetrion tetrion;
	Stack stack;
	Playfield playfield;
//	Console *console;
};

// When you have trouble thinking of good names for objects,
// refer to glossary of the game.
// Reference: http://tetris.wikia.com/wiki/Glossary
