
#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int		main(void)
{
	srand(time(NULL));

	Bureaucrat akali("Akali", 1);
	Bureaucrat ryze("Ryze", 22);
	Bureaucrat fiora("Fiora", 2);

	Form *f;

	Intern darius;

	f = darius.makeForm("robotomy request", "Jhin");
	if (f) {
		std::cout << *f << std::endl;
		try {
			akali.signForm(*f);
			akali.executeForm(*f);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << *f << std::endl;
	}

	std::cout << std::endl;

	f = darius.makeForm("pardon request", "Draven");
	if (f) {
		std::cout << *f << std::endl;
		try {
			ryze.signForm(*f);
			ryze.executeForm(*f);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << *f << std::endl;
	}

	std::cout << std::endl;

	f = darius.makeForm("shrubbery request", "home");
	if (f) {
		std::cout << *f << std::endl;
		try {
			fiora.signForm(*f);
			fiora.executeForm(*f);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << *f << std::endl;
	}

	std::cout << std::endl;

	f = darius.makeForm("blabla request", "home");
	if (f) {
		std::cout << *f << std::endl;
		try {
			akali.signForm(*f);
			akali.executeForm(*f);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << *f << std::endl;
	}

}