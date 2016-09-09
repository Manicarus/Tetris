
#include "block.h"

Block::Block() {}

Block::Block(float * newCenter) {
    for(int i = 0; i < DIMENSION; i++) {
        center[i] = newCenter[i];
    }
}

// copy contructor will be used when there is dynamic allocation
//Block::Block(const Block &box) {
//    width = box.width;
//}

void Block::move(float [] d) {
	for(int i = 0;i < DIMENSION; i++) {
		center[i] += d[i]
	}
}

void Block::draw() const {

}

void Block::changeColor(enum Color color) {
    switch(color) {
    case RED:
        
    	break;
    case GREEN:
        
        break;
    case BLUE:
        
        break;
    }
}
