#include "../header/tetrion.hpp"
#include "../header/buffer.hpp"

int main() {
	TetrisComponent *tetrion = new Tetrion(Coordinate(0, 0));

	tetrion->sketch();
	tetrion->getCanvas()->print();

	return 0;
}
