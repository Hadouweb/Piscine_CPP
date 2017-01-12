#include "FragTrap.hpp"
#include <iostream>

int		main(void)
{
	FragTrap akali("Akali");
	FragTrap katarina("Katarina");
	FragTrap soraka("Soraka");

	akali.vaulthunter_dot_exe(katarina.getName());
	katarina.vaulthunter_dot_exe(akali.getName());
	soraka.beRepaired(20);
	akali.vaulthunter_dot_exe(katarina.getName());
	akali.vaulthunter_dot_exe(katarina.getName());
	akali.vaulthunter_dot_exe(katarina.getName());
	katarina.takeDamage(80);
	katarina.takeDamage(110);
	akali.vaulthunter_dot_exe(katarina.getName());

	return 0;
}