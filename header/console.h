#ifndef __CONSOLE_H__
#define __CONSOLE_H__

#include <conio.h>
#include <string>
#include "component.h"
#include "buffer.h"

class Console : Component {
protected:
	Buffer buffer;

public:
	Console(std::string, Measure);
	void render();
};

#endif
