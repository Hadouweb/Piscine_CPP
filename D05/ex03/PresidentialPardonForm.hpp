#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form {
public:
	PresidentialPardonForm(std::string target);
	~PresidentialPardonForm(void);

	PresidentialPardonForm & operator=(PresidentialPardonForm const & rhs);

	virtual void execute(Bureaucrat const &executor) const;

private:
	PresidentialPardonForm(void);
	PresidentialPardonForm(PresidentialPardonForm const & src);
};

#endif