#ifndef __COMPONENT_H__
#define __COMPONENT_H__

class Component {
protected:


	Coordinate position;
	Measure size;
	void *data;

public:
	Component(Measure);
	Component(Measure, Coordinate);

	static Measure buildMeasure(int width, int height);

	int getSize();
};

#endif
