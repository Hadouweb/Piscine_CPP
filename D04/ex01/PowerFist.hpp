#ifndef POWER_FIST_HPP
# define POWER_FIST_HPP

#include "AWeapon.hpp"

class PowerFist : public AWeapon {
public:
	PowerFist(void);
	PowerFist(PowerFist const & src);
	~PowerFist(void);

	PowerFist & operator=(PowerFist const & rhs);

private:
	void attack() const;
};

#endif