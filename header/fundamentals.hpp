#ifndef __FUNDAMENTALS_HPP__
#define __FUNDAMENTALS_HPP__

typedef int dataType;

enum Data {
	EMPTY = 0,
	FIELD = 1,
	BLOCK = 2
};

class Coordinate {
private:
	int x;
	int y;
	
public:
	Coordinate() {
		x = 0;
		y = 0;
	}
	
	Coordinate(int paramX, int paramY) {
		x = paramX;
		y = paramY;
	};
	
	void setX(int paramX) {
		x = paramX;
	}
	
	void setY(int paramY) {
		y = paramY;
	}
	
	int getX() {
		return x;
	};
	
	int getY() {
		return y;
	};
};

class Dimension {
private:
	int width;
	int height;
	
public:
	Dimension() {
		width = 0;
		height = 0;
	};
	
	Dimension(int paramW, int paramH) {
		width = paramW;
		height = paramH;
	};
	
	int getSize() {
		return width * height;
	}
	
	int getWidth() {
		return width;
	};
	
	int getHeight() {
		return height;
	};
};

#endif
