#ifndef ZOMBIE_HORDE_HPP
# define ZOMBIE_HORDE_HPP

#include "Zombie.hpp"

class ZombieHorde {
public:
	ZombieHorde(int nb);
	~ZombieHorde(void);

private:
	static const std::string _nameData[];
	Zombie *_horde;
	int _nbZ;

	std::string _getRandomName(int i) const;
	void _announce(void) const;
};

#endif