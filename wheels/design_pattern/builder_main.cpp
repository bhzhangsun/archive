#include <iostream>
#include <memory>
#include "human.hpp"
#include "director.hpp"
using namespace design_pattern;
using std::cout;
using std::endl;
using std::unique_ptr;

int main()
{
	unique_ptr<Human> pthin(new ThinHuman);
	unique_ptr<Human> pfat(new FatHuman);
	Director dthin(pthin.get());
	Director dfat(pfat.get());

	dthin.Construct();
	dfat.Construct();
	return 0;
}
