#include "Intern.hpp"

Intern::Intern(void) { }

Intern::Intern(Intern const &src) {
	*this = src;
}

Intern::~Intern(void) { }

Intern &Intern::operator=(Intern const &rhs) {
	if (this != &rhs) {
	}
	return *this;
}

Form *Intern::makeForm(std::string form, std::string target) {
	if (form.compare("robotomy request") == 0) {
		return (new RobotomyRequestForm(target));
	}
	else if (form.compare("pardon request") == 0) {
		return (new PresidentialPardonForm(target));
	}
	else if (form.compare("shrubbery request") == 0) {
		return (new ShrubberyCreationForm(target));
	}
	else {
		std::cout << "Unknown Form: <" << form << ">" << std::endl;
	}
	return NULL;
}
