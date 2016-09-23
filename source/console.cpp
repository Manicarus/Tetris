#include "console.h"

Console::Console() {
	system("mode con:cols=100 lines=30");
	system("title Tetris");
}

void Console::render() { 

}

// Referenced: https://gist.github.com/enghqii/c8711c5f04d3f3d2f8f2
