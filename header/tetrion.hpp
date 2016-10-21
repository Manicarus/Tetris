#ifndef __TETRION_HPP__
#define __TETRION_HPP__

#include "tetris_component.hpp"

class Tetrion : public TetrisComponent {
public:
	Tetrion(Coordinate);
	void update();
	
private:
	void clearLine();
	void fix();
};

#endif
