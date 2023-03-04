#ifndef _DESIGN_PATTERN_FACADE_FACADE_HPP_
#define _DESIGN_PATTERN_FACADE_FACADE_HPP_
#include <iostream>
using std::cout;
using std::endl;

namespace design_pattern
{

class Stock
{
public:
	void BuyStock() 
	{
		cout << "BuyStock()" << endl;
	}
};

class Futures
{
public:
	void Transaction()
	{
		cout << "Transaction()" << endl;
	}
};

class Funds
{
private:
	Stock st;
	Futures fu;
public:
	void BuyStock() { st.BuyStock(); }
	void Transaction() { fu.Transaction(); }
};

}

#endif // !_DESIGN_PATTERN_FACADE_FACADE_HPP_