#ifndef __TETRIS_HPP__
#define __TETRIS_HPP__

#include "game.hpp"
#include "tetromino.hpp"
#include "tetrion.hpp"
#include "buffer.hpp"

class Tetris : public Game{
public:
	Tetris();
	~Tetris();

	void update();
	void render();
	void sketch();
	bool collide(TetrisComponent, TetrisComponent);

private:
	TetrisComponent *tetromino;
	TetrisComponent *tetrion;
};

#endif

// When you have trouble thinking of good names for objects,
// refer to glossary of the game.
// Reference: http://tetris.wikia.com/wiki/Glossary
