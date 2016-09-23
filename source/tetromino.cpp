#include <ctime>
#include <cstdlib>
#include <iostream>

#include "tetromino.h"
#include "common.h"
#include "windows.h"

Tetromino::Tetromino() {
    srand(static_cast<unsigned int>(time(NULL)));
    
//    enum TetrominoeType type = rand() % 7;
    
    setType((enum TetrominoType)(rand() % 7));
    setColor((enum Color)(rand() % 7));
    
    type = SQUARE;
    color = YELLOW;
    
    x = 4;
    y = 4;
}

Tetromino::~Tetromino() {
	
}

void Tetromino::setType(enum TetrominoType _type) {
    type = _type;
}

enum TetrominoType Tetromino::getType() {
    return type;
}

void Tetromino::setColor(enum Color _color) {
    color = _color;
}

enum Color Tetromino::getColor() {
    return color;
}

void Tetromino::setVisibility(bool isVisible) {
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			if(TetrominoLibrary[type][0][i][j]) {
				COORD cursorPos = {2 * (x + i), y + j};
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPos);
				std::cout << (isVisible ? "¢Ã": " ") << std::endl;
			}
		}
	}
}

bool Tetromino::collidesWith(Playfield playfield) {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
			if(TetrominoLibrary[type][0][i][j] && playfield.layer[-playfield.y + y + i][-playfield.x + x + j]) {
				return true;
			}
        }
    }
    
    return false;
}

enum Direction Tetromino::revertDir(enum Direction dir) {
	switch(dir) {
		case UP:
			return DOWN;
		case DOWN:
			return UP;
		case LEFT:
			return RIGHT;
		case RIGHT:
			return LEFT;
	}
}

//bool Tetromino::checkRotCollision() {
//    float tmpY, tmpZ;
//
//    for(int i = 0; i < 4; i++) {
//        tmpY = element[i].center[1];
//        tmpZ = element[i].center[2];
//        
//        for(int j = 0; j < boundary.element.size(); j++) {
//            if(boundary.element.at(j).center[1] == -(tmpZ - element[0].center[2]) + element[0].center[1]
//                && boundary.element.at(j).center[2] == (tmpY - element[0].center[1]) + element[0].center[2]) {
//                return true;
//            }
//        }
//    }
//    return false;
//}

void Tetromino::move(enum Direction dir) {
	// Originally made by yoonki1207
	switch(dir) {
		case LEFT:
			x--;
			break;

		case RIGHT:
			x++;
			break;

		case DOWN:
			y++;
			break;

		case UP:
			y--;
			break;
	}
}
//
//void Tetromino::rotate() {
//    float tmpY, tmpZ;
//    
//    for(int i = 0; i < 4; i++) {
//        tmpY = element[i].center[1];
//        tmpZ = element[i].center[2];
//        
//        // yÁÂÇ¥
//        element[i].center[1] = -(tmpZ - element[0].center[2]) + element[0].center[1];
//        // zÁÂÇ¥
//        element[i].center[2] = (tmpY - element[0].center[1]) + element[0].center[2];
//    }
//}
//
//void Tetromino::fix() {
//    for(int i = 0; i < 4; i++) {
//        boundary.element.push_back(element[i]);
//    }
//    
//    boundary.eraseLine();
//    
//    gameStatus = NEW_Tetromino;
//}
