#include <string>
#include <iostream>
#ifndef _DESIGN_PATTERN_BUILDER_HUMAN_HPP_
#define _DESIGN_PATTERN_BUILDER_HUMAN_HPP_

namespace design_pattern
{

class Human
{
public:
	virtual void Head() = 0;
	virtual void Features() = 0;
	virtual void Body() = 0;
	virtual void Arm() = 0;
	virtual void Lag() = 0;
	virtual void Foot() = 0;

	virtual ~Human() = default;
};

class ThinHuman : public Human
{
public:
	void Head()
	{
		std::cout << "Head";
	}
	void Features()
	{
		std::cout << "    Features";
	}
	void Body()
	{
		std::cout << "    Body Thin";
	}
	void Arm()
	{
		std::cout << "    Arm";
	}
	void Lag()
	{
		std::cout << "    Lag";
	}
	void Foot()
	{
		std::cout << "    Foot" << std::endl;
	}
};

class FatHuman : public Human
{
public:
	void Head()
	{
		std::cout << "Head";
	}
	void Features()
	{
		std::cout << "    Features";
	}
	void Body()
	{
		std::cout << "    Body Fat";
	}
	void Arm()
	{
		std::cout << "    Arm";
	}
	void Lag()
	{
		std::cout << "    Lag";
	}
	void Foot()
	{
		std::cout << "    Foot" << std::endl;
	}
};
}
#endif // !_DESIGN_PATTERN_BUILDER_HUMAN_HPP_
