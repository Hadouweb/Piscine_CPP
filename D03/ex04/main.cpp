#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"
#include <iostream>

int		main(void)
{
	srand(time(NULL));

	FragTrap akali("Akali");
	FragTrap katarina("Katarina");
	FragTrap soraka("Soraka");

	ScavTrap maokai("Maokai");
	ScavTrap janna("Janna");

	NinjaTrap shen("Shen");

	SuperTrap cait("Cait");

	shen.ninjaShoebox(katarina);
	shen.ninjaShoebox(janna);
	shen.ninjaShoebox(shen);
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
	cait.vaulthunter_dot_exe(soraka.getName());
	cait.ninjaShoebox(janna);
	cait.ninjaShoebox(shen);

	return 0;
}