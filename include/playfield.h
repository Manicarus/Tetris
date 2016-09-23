#pragma once

class Playfield{
public:
	bool *frontBuffer;
	bool *backBuffer;
	
	void flipBuffer();
};
