#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat {
public:
    Bureaucrat(void);
    Bureaucrat(std::string pName, int pNote);
    Bureaucrat(Bureaucrat const & src);

    ~Bureaucrat(void);

    Bureaucrat & operator=( Bureaucrat const & rhs);
	Bureaucrat & operator++(void);
	Bureaucrat operator++(int);
	Bureaucrat & operator--(void);
	Bureaucrat operator--(int);

	std::string getName(void) const;
	int getGrade(void) const;

	void signForm(Form & f) const;
	void executeForm(Form const & form);

	class GradeTooHighException : public std::exception {
		public:
			GradeTooHighException(void);
			GradeTooHighException(GradeTooHighException const & src);
			~GradeTooHighException(void) throw();
			GradeTooHighException & operator=(GradeTooHighException const & rhs);
			virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
		public:
			GradeTooLowException(void);
			GradeTooLowException(GradeTooLowException const & src);
			~GradeTooLowException(void) throw();
			GradeTooLowException & operator=(GradeTooLowException const & rhs);
			virtual const char* what() const throw();
	};

private:
	std::string const _name;
	int _grade;
};

std::ostream & operator<<(std::ostream & os, Bureaucrat const & b);

#endif