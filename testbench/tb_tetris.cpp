#include "../header/tetris.hpp"

#define SELECT 0

#if SELECT == 0

int main() {
    Tetris tetris;
    tetris.render();
    tetris.print();
    
    return 0;
}

#else

int main() {
    Tetris *tetris = new Tetris();
    tetris->render();
    tetris->print();
    
    return 0;
}

#endif
