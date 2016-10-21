#ifndef __CONSOLE_HPP__
#define __CONSOLE_HPP__

#include <conio.h>
#include <string>
#include "fundamentals.hpp"
#include "buffer.hpp"

// This should be a Singleton
// Taking Keyboard Input could be made with OOP Design Pattern
class Console{
public:
	static Console *getInstance();
	int getWidth();
	void sketchAt(int, dataType);
	void render();
	void flipBuffer();
	void clearBuffer();
	int getKBInput();
	
private:
	static Console *instance;
	Console(std::string);
	~Console();
	
	Dimension container;
	DoubleBuffer buffer;
	bool isArrowInput(int);
};

#endif
