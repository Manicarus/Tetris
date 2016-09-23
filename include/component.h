#pragma once

#include "playfield.h"

class Component {
public:
	Component();
	Component(Playfield *);
	void sketch();
	
protected:
	int x; int y;
	bool *data;
	
	Playfield *canvas;
};
