#include "../header/tetris_component.hpp"

int main() {
    TetrisComponent tComponent(Coordinate(2, 2), Dimension(4, 4));

    tComponent.sketch();
	tComponent.getCanvas()->print();

    return 0;
}
