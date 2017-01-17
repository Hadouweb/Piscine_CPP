#include <iostream>
#include "Convert.hpp"

int 	main(int ac, char **av) {
	if (ac > 1) {
		Convert c(av[1]);
		std::cout << "<" << c.getBase() << "> output: " << std::endl;
	} else {
		std::cout << "Usage: decimal parameter (char, int, float, double)" << std::endl;
	}
	return 0;
}