#include "../header/component.h"
#include <iostream>
#include <cstdlib>

Component::Component(
	Component::Coordinate coordinate = {0, 0}, 
	Component::Dimension dimension = {0, 0}, 
) : position(coordinate), size(dimension) { }

int Component::getSize() {
	return size.width * size.height;
}
