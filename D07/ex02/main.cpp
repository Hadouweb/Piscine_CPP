#include <iostream>
#include "Array.hpp"

int 	main(void) {
	Array<int> a(3);

	std::cout << a.getSize() << std::endl;

	return 0;
}