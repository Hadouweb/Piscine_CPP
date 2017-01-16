#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) { }

PresidentialPardonForm::PresidentialPardonForm(std::string target)
		: Form("PresidentialPardon", 25, 5) {
	this->setTarget(target);
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : Form(src) { }

PresidentialPardonForm::~PresidentialPardonForm(void) { }

PresidentialPardonForm &
PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs) {
	if (this != &rhs) {
		this->setTarget(rhs.getTarget());
	}
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	if (this->getSigned() && executor.getGrade() <= this->getGradeForExec())
		std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox" << std::endl;
	else
		throw Form::GradeTooLowException();
}
