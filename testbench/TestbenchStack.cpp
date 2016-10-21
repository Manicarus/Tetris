#include "../header/Stack.hpp"
#include <iostream>

int main() {
	Component stack;
	stack.sketch();
	
	for(int i = 0; i < stack.getSize(); i++) {
		std::cout << stack.getDataAt() << std::endl;
	}
	
	return 0;
}
