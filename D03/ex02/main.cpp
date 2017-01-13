#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int		main(void)
{
	FragTrap akali("Akali");
	FragTrap katarina("Katarina");
	FragTrap soraka("Soraka");

	ScavTrap maokai("Maokai");
	ScavTrap janna("Janna");

	ClapTrap mainAdc("Vayne");

	akali.vaulthunter_dot_exe(katarina.getName());
	katarina.vaulthunter_dot_exe(akali.getName());
	soraka.beRepaired(20);
	akali.vaulthunter_dot_exe(katarina.getName());
	akali.vaulthunter_dot_exe(katarina.getName());
	akali.vaulthunter_dot_exe(katarina.getName());
	katarina.takeDamage(80);
	katarina.takeDamage(110);
	akali.vaulthunter_dot_exe(katarina.getName());
	maokai.challengeNewcomer(janna.getName());
	maokai.takeDamage(10);
	mainAdc.takeDamage(50);
	mainAdc.rangedAttack(maokai.getName());

	return 0;
}