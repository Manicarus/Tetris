#ifndef __TETROMINO_HPP__
#define __TETROMINO_HPP__

#include "tetris_component.hpp"

enum Command {
	UP = 72,
	DOWN = 80,
	LEFT = 75,
	RIGHT = 77,
	ESC = 27
};

enum TetrominoType {
	SQUARE,
	BAR,
	R_SNAKE,
	L_SNAKE,
	R_GUN,
	L_GUN,
	T_SHAPE
};

enum Color {
	GREEN = 2,
	BLUE_GREEN,
	BLOOD,
	PURPLE,
	GOLE,
	ORIGINAL,
	GRAY,
	BLUE,
	HIGH_GREEN,
	SKY_BLUE,
	RED,
	PLUM,
	YELLOW
};

class Tetromino : public TetrisComponent {
public:
	Tetromino(Coordinate);
	void update();

	enum TetrominoType type;
    enum Color color;
    
    void move(enum Command);
    void rotate();

    void setType(enum TetrominoType type);
    enum TetrominoType getType();

    void setColor(enum Color color);
    enum Color getColor();

    void setVisibility(bool isVisible);
	static enum Command revert(enum Command);
};

#endif
