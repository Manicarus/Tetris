#ifndef __TETROMINO_H__
#define __TETROMINO_H__

#include "playfield.h"
#include "component.h"

enum Direction {
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

class Tetromino : public Imaginary {
public:
	Tetromino(Playfield *);
	~Tetromino();
	
    void move(enum Direction dir);
    void rotate();
    
    void setType(enum TetrominoType type);
    enum TetrominoType getType();
    
    void setColor(enum Color color);
    enum Color getColor();
    
    void setVisibility(bool isVisible);
    bool collidesWith(Playfield playfield);
	enum Direction revertDir(enum Direction dir);
	
private:
	
    enum TetrominoType type;
    enum Color color;    
};

#endif
