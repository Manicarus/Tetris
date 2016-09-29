#ifndef __COMPONENT_H__
#define __COMPONENT_H__

class Component {
protected:
	struct Coordinate {
		int x;
		int y;
	};

	struct Measure {
		int width;
		int height;
	};

	Coordinate position;
	Measure size;
	void *data;

public:
	Component(Measure, Coordinate);

	int getSize();
};

#endif
