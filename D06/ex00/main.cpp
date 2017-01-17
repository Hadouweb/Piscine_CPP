#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctgmath>

int 	main(int ac, char **av) {
	if (ac == 2) {
		double doubleValue = static_cast<double>(std::atof(av[1]));
		float floatValue = static_cast<float>(doubleValue);
		int intValue = static_cast<int>(doubleValue);
		char charValue = static_cast<char>(doubleValue);

		if (intValue < 0 || intValue > 127)
			std::cout << "char: " << "impossible" << std::endl;
		else if (isprint(charValue))
			std::cout << "char: '" << charValue << "'" << std::endl;
		else
			std::cout << "char: " << "Non displayable" << std::endl;

		if (doubleValue <= INT_MAX && doubleValue >= INT_MIN)
			std::cout <<  "int: " << intValue << std::endl;
		else
			std::cout << "int: " << "impossible" << std::endl;

		std::cout.precision(1);
		std::cout << "float: " << std::fixed << floatValue << 'f' << std::endl;
		std::cout << "double: " << std::fixed << doubleValue << std::endl;
	} else {
		std::cout << "Usage: parameter 1 (char, int, float, double)" << std::endl;
	}

	return 0;
}