#include "../header/console.hpp"
#include <windows.h>
#include <iostream>
#include <sstream>
#include <cstdlib>

Console *Console::instance;

Console *Console::getInstance() {
	if(instance == NULL) {
		instance = new Console("Tetris");
	}
	
	return instance;
}

Console::Console(std::string title) : container(Dimension(100, 30)), buffer(container) {
	std::string conTitleStr("title ");
	conTitleStr.append(title);

	std::string conDimStr("mode con:");

	std::string conWidthStr = "cols=";
	std::stringstream ss;
	ss << container.getWidth();
	conWidthStr.append(ss.str());

	ss.str("");
	std::string conHeightStr = " lines=";
	ss << container.getHeight();
	conHeightStr.append(ss.str());

	conDimStr.append(conWidthStr);
	conDimStr.append(conHeightStr);

	system(conDimStr.c_str());
	system(conTitleStr.c_str());
}

Console::~Console() {
	if(instance != NULL) {
		delete instance;
	}
}

int Console::getWidth() {
	return container.getWidth();
}

void Console::sketchAt(int dataIndex, dataType newData) {
	dataType oldData =  buffer.back->getDataAt(dataIndex);
	
	buffer.back->setDataAt(dataIndex, ((newData > oldData) ? newData : oldData));
}

void Console::render() {
	for(int i = 0; i < container.getSize(); i++) {
		
		if(buffer.isUnchanged(i)) {
			continue;
		}
	
		SHORT x = i % container.getWidth();
		SHORT y = i / container.getWidth();
		COORD cursorPosition = {x * 2, y};
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
	
		if(buffer.front->getDataAt(i) == BLOCK) {
			std::cout << "¢Ì";
		} else if(buffer.front->getDataAt(i) == FIELD) {
			std::cout << ". ";
		}
		
		if(x == container.getWidth() - 1) {
			std::cout << std::endl;
		}
	}
}

int Console::getKBInput() {
	int keyboardInput;
	
	if(kbhit()) {
		keyboardInput = getch();
		
		if(isArrowInput(keyboardInput)) {
			return getch();
		} else {
			return keyboardInput;
		}
	}
}

bool Console::isArrowInput(int keyboardInput) {
	return (keyboardInput == 0xE0 || keyboardInput == 0);
}

void Console::flipBuffer() {
	buffer.flip();
}

void Console::clearBuffer() {
	buffer.back->clear(container);
}

// Referenced: https://gist.github.com/enghqii/c8711c5f04d3f3d2f8f2
