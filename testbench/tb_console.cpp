#include "../header/console.h"
#include <string>
#include <cstdlib>

int main() {
    std::string str = std::string("Tetris");
    Console *console = new Console(str, 100, 30);

    system("pause");
    return 0;
}
