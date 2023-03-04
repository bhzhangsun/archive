#include <iostream>
#ifndef _DESIGN_PATTERN_ABSTRACT_FACTORY_WEAPON_HPP_
#define _DESIGN_PATTERN_ABSTRACT_FACTORY_WEAPON_HPP_

namespace design_pattern
{

class Weapon
{
public:
	virtual ~Weapon() {}
	virtual void Shoot() = 0;
};

class WeaponHandgun : public Weapon
{
public:
	void Shoot()
	{
		std::cout << "WeaponHandgun shoot: 10.0" << std::endl;
	}
};

class WeaponShotgun : public Weapon
{
public:
	void Shoot()
	{
		std::cout << "WeaponShotgun shoot: kill a goat" << std::endl;
	}
};

}

#endif //!_DESIGN_PATTERN_ABSTRACT_FACTORY_WEAPON_HPP_
