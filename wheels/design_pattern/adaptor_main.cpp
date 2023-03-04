#include "adaptor.hpp"
using namespace design_pattern;

int main()
{
	CAdaptor a;
	Target *ptr = dynamic_cast<Target *>(&a);
	ptr->Operation();

	Adaptee adt;
	OAdaptor o;
	o.set_padt(&adt);
	ptr = dynamic_cast<Target *>(&o);
	ptr->Operation();
	return 0;
}