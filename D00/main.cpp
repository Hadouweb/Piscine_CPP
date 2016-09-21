#include "Sample.class.hpp"
#include <iostream>

int main() {
	Sample instance('a', 'B');

	instance.foo = 3;
	std::cout << instance.f() << std::endl;
	std::cout << instance.foo << std::endl;

	return 0;
}