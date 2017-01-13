#ifndef NINJA_TRAP_HPP
# define NINJA_TRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

# define NB_ATK 5
# define FRAG_TRAP "FragTrap"
# define SCAV_TRAP "ScavTrap"
# define NINJA_TRAP "NinjaTrap"


class NinjaTrap : public virtual ClapTrap {
public:
    NinjaTrap(void);
	NinjaTrap(std::string pName);
    NinjaTrap(NinjaTrap const & src);
    ~NinjaTrap(void);

    NinjaTrap & operator=(NinjaTrap const & rhs);

    void ninjaShoebox(FragTrap & ft);
    void ninjaShoebox(ScavTrap & st);
    void ninjaShoebox(NinjaTrap & nt);

private:
	static const std::string _randAtkNinjaTrap[NB_ATK];
	static const std::string _randAtkFrag[NB_ATK];
	static const std::string _randAtkNScav[NB_ATK];
};

#endif