#include <iostream>

#ifndef _DESIGN_PATTERN_ABSTRACT_FACTORY_TOY_HPP_
#define _DESIGN_PATTERN_ABSTRACT_FACTORY_TOY_HPP_

namespace design_pattern
{
class Toy
{
public:
	virtual ~Toy() {}
	virtual void Shoot() = 0;
};

class ToyHandgun : public Toy
{
public:
	void Shoot()
	{
		std::cout << "ToyHandgun shoot: bi bi bu..." << std::endl;
	}
};

class ToyShotgun : public Toy
{
	void Shoot()
	{
		std::cout << "ToyShotgun shoot: so so so..." << std::endl;
	}
};
}
#endif // !_DESIGN_PATTERN_ABSTRACT_FACTORY_TOY_HPP_
