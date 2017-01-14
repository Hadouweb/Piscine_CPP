#ifndef ENEMY_HPP
# define ENEMY_HPP

#include <iostream>

class Enemy {
public:
	Enemy(int hp, std::string const & type);
    Enemy(Enemy const & src);

    virtual ~Enemy(void);

	std::string const getType(void) const;
	int getHP(void) const;

	virtual void takeDamage(int value);

    Enemy & operator=(Enemy const & rhs);

protected:
	std::string _type;
	int _hp;
	Enemy(void);
};

#endif