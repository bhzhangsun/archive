#include "car.hpp"
#include <string>

#ifndef _DESIGN_PATTERN_SIMPLE_FACTORY_FACTORYCAR_HPP_
#define _DESIGN_PATTERN_SIMPLE_FACTORY_FACTORYCAR_HPP_


namespace design_pattern
{
class FactoryCar
{
public:

	Car * CreateCar(std::string const &name)
	{
		if (name == std::string("BMW"))
			return new BMW;
		if (name == std::string("NIO"))
			return new NIO;
		return NULL;
	}
};
}

#endif //_DESIGN_PATTERN_SIMPLE_FACTORY_FACTORYCAR_HPP_
