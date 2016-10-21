#ifndef __TETRIS_COMPONENT_MEDIATOR_HPP__
#define __TETRIS_COMPONENT_MEDIATOR_HPP__

class TetrisComponentMediator {
public:
	update();
private:
	Tetromino *tetromino;
	Tetrion *tetrion;
};

#endif
