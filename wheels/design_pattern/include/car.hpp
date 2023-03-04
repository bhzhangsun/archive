#include <iostream>

#ifndef _DESIGN_PATTERN_SIMPLE_FACTORY_CAR_HPP_
#define _DESIGN_PATTERN_SIMPLE_FACTORY_CAR_HPP_

namespace design_pattern
{
class Car
{
public:
	virtual void name() = 0;
	virtual ~Car() = default;
protected:
	Car() = default;
};

class BMW : public Car
{
public:
	void name() override
	{
		std::cout << "my name is BMW" << std::endl;
	}
};

class NIO : public Car
{
public:
	void name() override
	{
		std::cout << "my name is NIO" << std::endl;
	}
};
}

#endif //_DESIGN_PATTERN_SIMPLE_FACTORY_CAR_HPP_