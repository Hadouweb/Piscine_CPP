
#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int		main(void)
{
	srand(time(NULL));

	Bureaucrat akali("Akali", 1);
	Bureaucrat ryze("Ryze", 22);
	Bureaucrat fiora("Fiora", 2);
	ShrubberyCreationForm maokai("maokai");
	PresidentialPardonForm formA("formA");
	RobotomyRequestForm formB("formB");

	std::cout << akali << std::endl;
	std::cout << maokai << std::endl;
	try {
		akali.signForm(maokai);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << akali << std::endl;
	std::cout << maokai << std::endl;
	std::cout << std::endl;

	std::cout << akali << std::endl;
	std::cout << maokai << std::endl;
	try {
		akali.executeForm(maokai);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << akali << std::endl;
	std::cout << maokai << std::endl;
	std::cout << std::endl;

	std::cout << ryze << std::endl;
	std::cout << formA << std::endl;
	try {
		ryze.signForm(formA);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << ryze << std::endl;
	std::cout << formA << std::endl;
	std::cout << std::endl;

	std::cout << ryze << std::endl;
	std::cout << formA << std::endl;
	try {
		ryze.executeForm(formA);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << ryze << std::endl;
	std::cout << formA << std::endl;
	std::cout << std::endl;

	std::cout << fiora << std::endl;
	std::cout << formB << std::endl;
	try {
		fiora.executeForm(formB);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << fiora << std::endl;
	std::cout << formB << std::endl;
	std::cout << std::endl;

	std::cout << fiora << std::endl;
	std::cout << formB << std::endl;
	try {
		fiora.signForm(formB);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << fiora << std::endl;
	std::cout << formB << std::endl;
	std::cout << std::endl;

	std::cout << akali << std::endl;
	std::cout << formB << std::endl;
	try {
		akali.executeForm(formB);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << akali << std::endl;
	std::cout << formB << std::endl;
	std::cout << std::endl;
}