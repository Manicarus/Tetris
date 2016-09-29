#ifndef __IMAGINARY_H__
#define __IMAGINARY_H__

#include "component.h"
#include "buffer.h"

class Imaginary : public Component{
protected:
	Buffer *playfield;

public:
	Imaginary(
		Buffer *,
		Measure,
		Coordinate
	);
	void sketch();
};

#endif
