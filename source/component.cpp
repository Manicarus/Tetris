#include "../header/component.h"

Component::Component(
	Component::Measure measure = {0, 0},
	Component::Coordinate coordinate = {0, 0}
) : position(coordinate), size(measure) { }

int Component::getSize() {
	return size.width * size.height;
}
