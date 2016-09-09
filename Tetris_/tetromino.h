#pragma once
enum TetrominoType {
	SQUARE,
	BAR,
	R_SNAKE,
	L_SNAKE,
	R_GUN,
	L_GUN,
	T_SHAPE
};

enum Direction {
	UP,
	DOWN,
	LEFT,
	RIGHT
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

class Tetromino {
public:
	Tetromino();
	
    void move(enum Direction dir);
    void rotate();
    
    void setType(enum TetrominoType type);
    enum TetrominoType getType();
    
    void setColor(enum Color color);
    enum Color getColor();
    
    void draw();
    
private:

	
    enum TetrominoType type;
    enum Color color;
};
