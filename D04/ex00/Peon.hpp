#ifndef PEON_HPP
# define PEON_HPP

#include "Victim.hpp"

class Peon : public Victim {
public:
    Peon(Peon const & src);
	Peon(std::string pName);
    ~Peon(void);
    Peon & operator=(Peon const & rhs);

	void getPolymorphed(void) const;

private:
	Peon(void);
};

#endif