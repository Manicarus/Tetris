#ifndef __GAME_H__
#define __GAME_H__

class Game {
public:
	Game();
	~Game();
	virtual void update() = 0;
	virtual void render() = 0;
};

#endif
