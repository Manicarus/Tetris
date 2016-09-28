#ifndef __IMAGINARY_H__
#define __IMAGINARY_H__

#include "component.h"
#include "buffer.h"

class Imaginary : Component{
protected:
	Buffer *playfield;
		
public:
	void sketch();
};

#endif
