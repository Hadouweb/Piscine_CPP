#ifndef VICTIM_HPP
# define VICTIM_HPP

#include <iostream>

class Victim {
public:
	Victim(Victim const & src);
	Victim(std::string pName);
	virtual ~Victim(void);
	Victim & operator=(Victim const & rhs);

	const std::string &getName(void) const;

	virtual void getPolymorphed(void) const;

protected:
	Victim(void);
	std::string _name;
};

std::ostream& operator<<(std::ostream& os, const Victim& s);

#endif