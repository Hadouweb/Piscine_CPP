#ifndef ROBOTOMY_REQUEST_HPP
# define ROBOTOMY_REQUEST_HPP

#include "Form.hpp"

class RobotomyRequestForm : public Form {
public:
	RobotomyRequestForm(std::string target);
	~RobotomyRequestForm(void);

	RobotomyRequestForm & operator=(RobotomyRequestForm const & rhs);

	virtual void execute(Bureaucrat const &executor) const;

private:
	RobotomyRequestForm(void);
	RobotomyRequestForm(RobotomyRequestForm const & src);
};

#endif