#ifndef _DESIGN_PATTERN_BRIDGE_BRAND_HPP_
#define _DESIGN_PATTERN_BRIDGE_BRAND_HPP_
#include "software.hpp"
namespace design_pattern
{

class Brand
{
protected:
	Software *psoft_;
public:
	virtual ~Brand() {}
	
	void set_psoft(Software * const ptr)
	{
		psoft_ = ptr;
	}

	virtual void Operation() = 0;
};

class OPPO : public Brand
{
public:
	void Operation()
	{
		psoft_->Operation();
	}
};

class VIVO : public Brand
{
public:
	void Operation()
	{
		psoft_->Operation();
	}
};
}

#endif // !_DESIGN_PATTERN_BRIDGE_BRAND_HPP_
