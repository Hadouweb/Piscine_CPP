#include <iostream>
#include "Bureaucrat.hpp"

int 	main(void) {

	try {
		Bureaucrat jhon("Jhon", 2);
		std::cout << jhon << std::endl;
		jhon++;
		std::cout << jhon << std::endl;
		jhon++;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat batman("Batman", 149);
		std::cout << batman << std::endl;
		batman--;
		std::cout << batman << std::endl;
		batman--;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat akali("Akali", 3);
		Bureaucrat katarina("Katarina", 120);
		std::cout << akali << std::endl;
		std::cout << katarina << std::endl;
		katarina = akali;
		std::cout << akali << std::endl;
		std::cout << katarina << std::endl;

		std::cout << ++katarina << std::endl;
		std::cout << ++katarina << std::endl;
		std::cout << ++katarina << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}


	return 0;
}