#include "composite.hpp"
#include <memory>
using std::unique_ptr;
using namespace design_pattern;

int main()
{
	Filiale root;
	unique_ptr<Compnent> lf(new Finance);
	unique_ptr<Compnent> lhr(new HumanResource);
	Office of;
	root.Add(lf.get());
	root.Add(lhr.get());
	root.Add(&of);

	root.Operation();
	return 0;
}