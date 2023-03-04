#include "decorator.hpp"
using namespace design_pattern;

int main()
{
	Call c;
	Web w;
	Decorator *pd = dynamic_cast<Decorator *>(&w);
	pd->set_pmain(dynamic_cast<Cellphone *>(&c));
	pd->Operation();

	return 0;
}