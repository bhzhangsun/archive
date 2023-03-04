#ifndef _DESIGN_PATTERN_BRIDGE_SOFTWARE_HPP_
#define _DESIGN_PATTERN_BRIDGE_SOFTWARE_HPP_

#include <iostream>
using std::cout;
using std::endl;

namespace design_pattern
{
class Software
{
public:
	virtual void Operation() = 0;

	virtual ~Software() {}
};

class CallSoftware : public Software
{
public:
	void Operation()
	{
		cout << "Calling！！！" << endl;
	}
};

class GameSoftware : public Software
{
public:
	void Operation()
	{
		cout << "Playing Game!!!" << endl;
	}
};
}

#endif // !_DESIGN_PATTERN_BRIDGE_SOFTWARE_HPP_