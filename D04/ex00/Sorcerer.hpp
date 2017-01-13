#ifndef SORCERER_HPP
# define SORCERER_HPP

#include <iostream>
#include "Victim.hpp"

class Sorcerer {
public:
	Sorcerer(Sorcerer const & src);
	Sorcerer(std::string pName, std::string pTitle);
	~Sorcerer(void);
	Sorcerer & operator=(Sorcerer const & rhs);

	const std::string &getName(void) const;
	const std::string &getTitle(void) const;

	void polymorph(Victim const & v) const;

private:
	Sorcerer(void);
	std::string _name;
	std::string _title;
};

std::ostream& operator<<(std::ostream& os, const Sorcerer& s);

#endif