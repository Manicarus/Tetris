#include <ctime>
#include <cstdlib>

#include "tetromino.h"

Tetromino::Tetromino() {
    srand(static_cast<unsigned int>(time(NULL)));
    
//    enum TetrominoeType type = rand() % 7;
    
    setType((enum TetrominoType)(rand() % 7));
    setColor((enum Color)(rand() % 7));
    
    type = SQUARE;
    color = YELLOW;
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

void Tetromino::draw()
{
	
}

//bool Tetromino::checkCollision(float x, float y, float z) {
//    for(int i = 0; i < 4; i++) {
//        for(int j = 0; j < boundary.element.size(); j++) {
//            if(boundary.element.at(j).center[0] == (element[i].center[0] + x)
//               && boundary.element.at(j).center[1] == (element[i].center[1] + y)
//               && boundary.element.at(j).center[2] == (element[i].center[2] + z)) {
//                return true;
//            }
//        }
//    }
//    
//    return false;
//}
//
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
			if(enable_move_left) {
				for(int i = 0; i < 4; i++) {
					for(int j = 0; j < 4; j++) {
						if (blocks[b_type][b_turn][i][j]==1) {
							walls[b_y+j][b_x+i]=0;
						}
					}
				}
				for(i=0; i<4; i++) {
					for(j=0; j<4; j++) {
						if (blocks[b_type][b_turn][i][j]==1) {
							walls[b_y+j][b_x+i-1]=1;
						}
					}
				}
				b_x--;
			}
			break;

		case RIGHT:
			if(enable_move_right) {
				for(i=0; i<4; i++) {
					for(j=0; j<4; j++) {
						if (blocks[b_type][b_turn][i][j]==1) {
							walls[b_y+j][b_x+i]=0;
						}
					}
				}
				for(i=0; i<4; i++) {
					for(j=0; j<4; j++) {
						if (blocks[b_type][b_turn][i][j]==1) {
							walls[b_y+j][b_x+i+1]=1;
						}
					}
				}
				b_x++;
			}
			break;

		case DOWN:
			if(enable_move_down) {
				for(i=0; i<4; i++) {
					for(j=0; j<4; j++) {
						if (blocks[b_type][b_turn][i][j]==1) {
							walls[b_y+j][b_x+i]=0;
						}
					}
				}
				for(i=0; i<4; i++) {
					for(j=0; j<4; j++) {
						if (blocks[b_type][b_turn][i][j]==1) {
							walls[b_y+j+1][b_x+i]=1;
						}
					}
				}
				b_y++;
			}
			break;

		case UP:
			if(enable_move_up==1) {
				for(i=0; i<4; i++) {
					for(j=0; j<4; j++) {
						if (blocks[b_type][b_turn][i][j]==1) {
							walls[b_y+j][b_x+i]=0;
						}
					}
				}
				b_turn=(b_turn+1)%4;
				for(i=0; i<4; i++) {
					for(j=0; j<4; j++) {
						if (blocks[b_type][b_turn][i][j]==1) {
							walls[b_y+j][b_x+i]=1;
						}
					}
				}
			}
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
