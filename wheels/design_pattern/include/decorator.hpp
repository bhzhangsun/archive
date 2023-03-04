#ifndef _DESIGN_PATTERN_DECORATOR_DECORATOR_HPP_
#define _DESIGN_PATTERN_DECORATOR_DECORATOR_HPP_

#include <iostream>
using std::cout;
using std::endl;

namespace design_pattern
{

class Cellphone
{
public:
	~Cellphone() {}
	virtual void Operation() = 0;
};

class Call : public Cellphone
{
public:
	void Operation()
	{
		cout << "Calling... ...！" << endl;
	}
};

class Decorator : public Cellphone
{
protected:
	Cellphone *pmain_;

public:
	void set_pmain(Cellphone * const &ptr)
	{
		pmain_ = ptr;
	}

	virtual void Operation() = 0;
};

class Web : public Decorator
{
public:
	void Operation()
	{
		cout << "Browse Web Page... ...!" << endl;
		if (nullptr != pmain_)
			pmain_->Operation();
	}
};
}

#endif // !_DESIGN_PATTERN_DECORATOR_DECORATOR_HPP_