#pragma once

#include <windows.h>
#include "tetris.h"

class Console {
public: 
	Console();
	~Console();
	
	void render();
	
private:
	int width;
	int height;
	int *canvas;
};
