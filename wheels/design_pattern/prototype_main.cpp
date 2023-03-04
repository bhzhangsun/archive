#include <iostream>
#include <memory>
#include "prototype.hpp"
using design_pattern::Prototype;
using design_pattern::ConcretePrototype;
using std::unique_ptr;
using std::make_unique;
using std::cout;
using std::endl;

int main()
{
	ConcretePrototype c;
	Prototype * prot = &c;
	unique_ptr<Prototype *> prot1 = make_unique<Prototype *>(prot->Clone());

	cout << "proto: " << &prot << "  clone proto: " << prot1.get() << endl;
	return 0;
}
