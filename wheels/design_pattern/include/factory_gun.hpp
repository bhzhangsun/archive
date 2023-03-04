#include "weapon.hpp"
#include "toy.hpp"

#ifndef _DESIGN_PATTERN_ABSTRACT_FACTORY_FACTORY_GUN_HPP_
#define _DESIGN_PATTERN_ABSTRACT_FACTORY_FACTORY_GUN_HPP_

namespace design_pattern
{

class FactoryGun
{
public:
	virtual ~FactoryGun() {}

	virtual Weapon* CreateWeapon() = 0;
	virtual Toy*  CreateToy() = 0;
};

class FactoryHandgun : public FactoryGun
{
public:
	Weapon* CreateWeapon()
	{
		return new WeaponHandgun;
	}

	Toy* CreateToy()
	{
		return new ToyHandgun;
	}

};
class FactoryShotgun : public FactoryGun
{
	Weapon* CreateWeapon()
	{
		return new WeaponShotgun;
	}

	Toy* CreateToy()
	{
		return new ToyShotgun;
	}
};
}
#endif // !_DESIGN_PATTERN_ABSTRACT_FACTORY_FACTORY_GUN_HPP_
