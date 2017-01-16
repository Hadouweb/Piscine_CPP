#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
public:
    Form(void);
    Form(std::string pName, int pGradeForSign, int pGradeForExec);
    Form(Form const & src);

    ~Form(void);

    Form & operator=(Form const & rhs);

    std::string getName(void) const;
    bool getSigned(void) const;
    int getGradeForSign(void) const;
    int getGradeForExec(void) const;

    void setTarget(std::string target);
    std::string getTarget(void) const;

	void beSigned(Bureaucrat & b);
	virtual void execute(Bureaucrat const & executor) const = 0;

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
	bool _signed;
	int const _gradeForSign;
	int const _gradeForExec;
	std::string _target;
};

std::ostream & operator<<(std::ostream & os, Form const & f);

#endif