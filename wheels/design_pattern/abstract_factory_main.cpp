#include "weapon.hpp"
#include "toy.hpp"
#include "factory_gun.hpp"
using namespace design_pattern;

int main()
{
	FactoryGun *phand = new FactoryHandgun;
	FactoryGun *pshot = new FactoryShotgun;

	Weapon *pwhg = phand->CreateWeapon();
	Toy *pthg = phand->CreateToy();

	Weapon *pwsg = pshot->CreateWeapon();
	Toy *ptsg = pshot->CreateToy();

	pwhg->Shoot();
	pwsg->Shoot();
	pthg->Shoot();
	ptsg->Shoot();

	return 0;
}
