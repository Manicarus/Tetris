#include <Windows.h>
#include "cursor.h"

void Cursor::move(int x, int y) {
	COORD CursorPosition = {x * 2, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPosition);
}
