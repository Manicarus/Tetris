#ifndef __COMPONENT_H__
#define __COMPONENT_H__

class Component {
protected:
	struct Coordinate {
		int x;
		int y;
	};
	
	struct Dimension {
		int width;
		int height;
	};
	
	Coordinate position;
	Dimension size;
	void *data;
	
public:
	Component(
		Coordinate coordinate, 
		Dimension dimension, 
	);
	
	int getSize();
};

#endif
