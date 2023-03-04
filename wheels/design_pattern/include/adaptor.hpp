#ifndef _DESIGN_PATTERN_ADAPTOR_ADAPTOR_HPP_
#define _DESIGN_PATTERN_ADAPTOR_ADAPTOR_HPP_
#include <iostream>
using std::cout;
using std::endl;

namespace design_pattern
{

class Target
{
public:
	virtual ~Target() {}
	virtual void Operation() { cout << "Target : Operation()" << endl; }
};

class Adaptee
{
public:
	void SpecificOperation() { cout << "Adaptee : SpecificOperation()" << endl; }
};

class CAdaptor : public Target, public Adaptee
{
public:
	void Operation()
	{
		(dynamic_cast<Adaptee *>(this))->SpecificOperation();
	}
};

class OAdaptor : public Target
{
private:
	Adaptee *padt_;

public:

	void set_padt(Adaptee *const ptr)
	{
		padt_ = ptr;
	}

	void Operation()
	{
		padt_->SpecificOperation();
	}
};
}

#endif //!_DESIGN_PATTERN_ADAPTOR_ADAPTOR_HPP_