#include "../header/tetris.hpp"

#include <cstdlib>
#include <windows.h>

int main() {
	
	Tetris tetris;
	
	while(true) {
		tetris.update();
		tetris.render();
//		Sleep(300);
	}
	
	return 0;
}
