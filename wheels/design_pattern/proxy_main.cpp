#include "proxy.hpp"
using namespace design_pattern;

int main()
{
	BlueCat b;
	FeiFei f(&b);

	f.SendFlower();
	return 0;
}