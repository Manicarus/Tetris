#ifndef __BUFFER_H__
#define __BUFFER_H__

#include "component.h"

class Buffer : public Component{
private:
	bool *front;
	bool *back;
			
public:	
	Buffer(Coordinate, Dimension);
	~Buffer();
	int getSize();
	int getWidth();
	void flip();
	void setData(int pos, bool data);
};

#endif
