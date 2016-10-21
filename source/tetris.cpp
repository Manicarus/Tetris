#include "../header/tetris.hpp"
#include "../header/console.hpp"
#include <iostream>
#include <cstdlib>

Tetris::Tetris() {
	tetromino = new Tetromino(Coordinate(4, 2));
	tetrion = new Tetrion(Coordinate(0, 0));
}
 
Tetris::~Tetris() {
	if(tetromino != NULL) {
		delete tetromino;
	}
	
	if(tetrion != NULL) {
		delete tetrion;
	}
}

void Tetris::render() {
	sketch();
	Console::getInstance()->flipBuffer();
	Console::getInstance()->render();
}

void Tetris::sketch() {
	Console::getInstance()->clearBuffer();
	
	int canvasIndex;
	int canvasX;
	int canvasY;
	
	for(int i = 0; i < tetrion->getSize(); i++) {
		canvasX = i % tetrion->getWidth() + tetrion->getX();
		canvasY = i / tetrion->getWidth() + tetrion->getY();
		canvasIndex = canvasX + canvasY * Console::getInstance()->getWidth();
		Console::getInstance()->sketchAt(canvasIndex, tetrion->getDataAt(i));
	}
	
	for(int i = 0; i < tetromino->getSize(); i++) {
		canvasX = i % tetromino->getWidth() + tetromino->getX();
		canvasY = i / tetromino->getWidth() + tetromino->getY();
		canvasIndex = canvasX + canvasY * Console::getInstance()->getWidth();
		Console::getInstance()->sketchAt(canvasIndex, tetromino->getDataAt(i));
	}
}

void Tetris::update() {
//	int keyboardInput = console.getKBInput();
//	switch(keyboardInput) {
//		case ESC:
//			system("cls");
//			exit(0);
//			break;
//			
//		default:
//			tetromino->update();
//			break;
//	}
	int keyboardInput = Console::getInstance()->getKBInput();
	
	tetromino->move((Command)keyboardInput);
	
	if(collide(tetromino, tetrion)) {
		tetromino->move(Tetromino::revert((Command)keyboardInput);
	}
}

bool Tetris::collide(TetrisComponent *tetromino, TetrisComponent *tetrion) {
	
	int globalX;
	int globalY;
	
	for(int i = 0; i < tetromino->getSize(); i++) {
		if(tetromino->getDataAt(i) == BLOCK) {
			globalX = tetromino->getX() + (i % tetromino->getWidth());
			globalY = tetromino->getY() + (i / tetromino->getWidth());
			
			j = (globalX - tetrion->getX()) + (globalY - tetrion->getY()) * tetrion->getWidth();
			if(!(j < tetrion->getSize())) {
				continue;
			}
			
			if(tetrion->getDataAt(j) == BLOCK) {
				return true;
			}
		}
    }

	return false;
}
