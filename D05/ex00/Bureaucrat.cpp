#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("Unknown"), _grade(150) {

}

Bureaucrat::Bureaucrat(std::string pName, int pNote)
	: _name(pName), _grade(pNote) {
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade < 1)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) {
	*this = src;
}

Bureaucrat::~Bureaucrat(void) {

}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs) {
	if (this != &rhs)
	{
		this->_grade = rhs.getGrade();
	}
	return *this;
}

std::string Bureaucrat::getName(void) const {
	return this->_name;
}

int Bureaucrat::getGrade(void) const {
	return this->_grade;
}

Bureaucrat &Bureaucrat::operator++(void) {
	this->_grade--;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	return *this;
}

Bureaucrat Bureaucrat::operator++(int) {
	Bureaucrat tmp(*this);
	this->_grade--;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	return tmp;
}

Bureaucrat &Bureaucrat::operator--(void) {
	this->_grade++;
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	return *this;
}

Bureaucrat Bureaucrat::operator--(int) {
	Bureaucrat tmp(*this);
	this->_grade++;
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	return tmp;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(void) { }

Bureaucrat::GradeTooHighException::GradeTooHighException(
		const Bureaucrat::GradeTooHighException &src) {
	*this = src;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException(void) throw() { }

Bureaucrat::GradeTooHighException &Bureaucrat::GradeTooHighException::operator=(
		const Bureaucrat::GradeTooHighException &rhs) {
	if (this != &rhs) {

	}
	return *this;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too hight";
}

Bureaucrat::GradeTooLowException::GradeTooLowException(void) { }

Bureaucrat::GradeTooLowException::GradeTooLowException(
		const Bureaucrat::GradeTooLowException &src) {
	*this = src;
}

Bureaucrat::GradeTooLowException::~GradeTooLowException(void) throw() { }

Bureaucrat::GradeTooLowException &Bureaucrat::GradeTooLowException::operator=(
		const Bureaucrat::GradeTooLowException &rhs) {
	if (this != &rhs) {

	}
	return *this;
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &b) {
	os << "<" << b.getName() << ">, bureaucrat grade <" << b.getGrade() << ">";
	return os;
}
