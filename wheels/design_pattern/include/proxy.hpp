#ifndef _DESIGN_PATTERN_PROXY_PROXY_HPP_
#define _DESIGN_PATTERN_PROXY_PROXY_HPP_

#include <iostream>
using std::cout;
using std::endl;

namespace design_pattern
{

class Flower
{
public:
	virtual ~Flower() {}
	virtual void SendFlower() = 0;
};

class BlueCat
{
public:
	void SendFlower()
	{
		cout << "BlueCat : This is give your flowers!" << endl;
	}
};

class FeiFei
{
	BlueCat *pbeproxy_;
public:
	FeiFei(BlueCat *ptr) : pbeproxy_(ptr) {}
	void SendFlower()
	{
		pbeproxy_->SendFlower();
	}
};

}

#endif // !_DESIGN_PATTERN_PROXY_PROXY_HPP_