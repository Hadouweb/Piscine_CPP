#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) { }

RobotomyRequestForm::RobotomyRequestForm(std::string target)
		: Form("RobotomyRequestForm", 72, 45) {
	this->setTarget(target);
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : Form(src) { }

RobotomyRequestForm::~RobotomyRequestForm(void) { }

RobotomyRequestForm &
RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs) {
	if (this != &rhs) {
		this->setTarget(rhs.getTarget());
	}
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	if (this->getSigned() && executor.getGrade() <= this->getGradeForExec()) {
		if (rand() % 2)
			std::cout << "<" << this->getTarget() << "> has been robotomized successfully." << std::endl;
		else
			std::cout << "<" << this->getTarget() << "> robotomization failure." << std::endl;
	}
	else
		throw Form::GradeTooLowException();
}
