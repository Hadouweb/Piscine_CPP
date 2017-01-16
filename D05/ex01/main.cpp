#include <iostream>
#include "Bureaucrat.hpp"

int 	main(void) {

	Bureaucrat jhon("Jhon", 42);
	Bureaucrat kiwi("Kiwi", 120);
	Form formA("formA", 100, 50);
	Form formB("formB", 1, 1);

	try {
		Form f("f", 151, 1);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Form f("f", 150, 0);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << formA << std::endl;
	try {
		kiwi.signForm(formA);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << formA << std::endl;

	std::cout << formA << std::endl;
	try {
		jhon.signForm(formA);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << formA << std::endl;

	std::cout << std::endl;

	std::cout << jhon << std::endl;
	std::cout << formB << std::endl;
	try {
		formB.beSigned(jhon);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << jhon << std::endl;
	std::cout << formB << std::endl;

	while (jhon.getGrade() > 1)
		jhon++;

	std::cout << jhon << std::endl;
	std::cout << formB << std::endl;
	try {
		formB.beSigned(jhon);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << jhon << std::endl;
	std::cout << formB << std::endl;

	return 0;
}