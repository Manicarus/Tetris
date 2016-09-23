#pragma once

class Game {
	virtual void init() = 0;
	virtual void update() = 0;
	virtual void render() = 0;
	virtual void release() = 0;
};
