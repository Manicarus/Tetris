#include <ctime>
#include <cstdlib>
#include <iostream>

#include "../header/tetromino.hpp"
#include "../header/common.h"
#include "../header/console.hpp"

Tetromino::Tetromino(Coordinate coordinate) 
: TetrisComponent(coordinate, Dimension(4, 4)) {
    srand(static_cast<unsigned int>(time(NULL)));

    setType((enum TetrominoType)(rand() % 7));
    setColor((enum Color)(rand() % 7));
    
	for(int i = 0; i < container.getSize(); i++) {
		data[i] = ((TetrominoLibrary[type][0][0][i]) ? BLOCK : EMPTY);
	}
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

//void Tetromino::setVisibility(bool isVisible) {
//	for(int i = 0; i < 4; i++) {
//		for(int j = 0; j < 4; j++) {
//			if(TetrominoLibrary[type][0][i][j]) {
//				COORD cursorPos = {2 * (x + i), y + j};
//				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPos);
//				std::cout << (isVisible ? "��": " ") << std::endl;
//			}
//		}
//	}
//}

enum Command Tetromino::revert(enum Command command) {
	switch(command) {
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

void Tetromino::move(enum Command command) {
	// Originally made by yoonki1207
	switch(command) {
		case LEFT:
			position.setX(position.getX() - 1);
			break;

		case RIGHT:
			position.setX(position.getX() + 1);
			break;

		case DOWN:
			position.setY(position.getY() + 1);
			break;

		case UP:
			position.setY(position.getY() - 1);
			break;
	}
}

//void Tetromino::rotate() {
//    float tmpY, tmpZ;
//
//    for(int i = 0; i < 4; i++) {
//        tmpY = element[i].center[1];
//        tmpZ = element[i].center[2];
//
//        // y��ǥ
//        element[i].center[1] = -(tmpZ - element[0].center[2]) + element[0].center[1];
//        // z��ǥ
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
