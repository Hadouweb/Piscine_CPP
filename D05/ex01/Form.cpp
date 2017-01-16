#include "Form.hpp"

Form::Form(void) : _name("DefaultForm"), _gradeForSign(1), _gradeForExec(1) {
	this->_signed = 0;
}

Form::Form(std::string pName, int pGradeForSign, int pGradeForExec)
	: _name(pName), _gradeForSign(pGradeForSign), _gradeForExec(pGradeForExec) {
	this->_signed = 0;
	if (this->_gradeForSign < 1 || this->_gradeForExec < 1)
		throw Form::GradeTooHighException();
	else if (this->_gradeForSign > 150 || this->_gradeForExec > 150)
		throw Form::GradeTooLowException();
}

Form::Form(Form const &src)
	: _name(src.getName()), _gradeForSign(src.getGradeForSign()), _gradeForExec(src.getGradeForExec()) {
	*this = src;
}

Form::~Form(void) {

}

Form &Form::operator=(Form const &rhs) {
	if (this != &rhs)
	{
		this->_signed = rhs.getSigned();
	}
	return *this;
}

std::string Form::getName(void) const {
	return this->_name;
}

bool Form::getSigned(void) const {
	return this->_signed;
}

int Form::getGradeForSign(void) const {
	return this->_gradeForSign;
}

int Form::getGradeForExec(void) const {
	return this->_gradeForExec;
}

Form::GradeTooHighException::GradeTooHighException(void) { }

Form::GradeTooHighException::GradeTooHighException(
		const Form::GradeTooHighException &src) {
	*this = src;
}

Form::GradeTooHighException::~GradeTooHighException(void) throw() { }

Form::GradeTooHighException &Form::GradeTooHighException::operator=(
		const Form::GradeTooHighException &rhs) {
	if (this != &rhs) {

	}
	return *this;
}

const char *Form::GradeTooHighException::what() const throw() {
	return "Grade too hight";
}

Form::GradeTooLowException::GradeTooLowException(void) { }

Form::GradeTooLowException::GradeTooLowException(
		const Form::GradeTooLowException &src) {
	*this = src;
}

Form::GradeTooLowException::~GradeTooLowException(void) throw() { }

Form::GradeTooLowException &Form::GradeTooLowException::operator=(
		const Form::GradeTooLowException &rhs) {
	if (this != &rhs) {

	}
	return *this;
}

const char *Form::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

void Form::beSigned(Bureaucrat &b) {
	if (b.getGrade() <= this->getGradeForSign())
		this->_signed = 1;
	else
		throw Form::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os, Form const &f) {
	if (f.getSigned())
		os << "<" << f.getName() << ">, require grade <" <<
			f.getGradeForSign() << "> for sign, <" << f.getGradeForExec() << "> for execute and he is signed";
	else
		os << "<" << f.getName() << ">, require grade <" <<
		   f.getGradeForSign() << "> for sign, <" << f.getGradeForExec() << "> for execute and he is not signed";
	return os;
}
