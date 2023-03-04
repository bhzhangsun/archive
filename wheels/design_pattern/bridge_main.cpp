#include "brand.hpp"
#include "software.hpp"
#include <memory>
#include <typeinfo>
using std::cout;
using std::endl;
using std::unique_ptr;
using std::make_unique;
using namespace design_pattern;

int main()
{
	
	unique_ptr<Software> ptr(new CallSoftware);
	OPPO oppo;
	Brand *poppo = &oppo;
	cout << ptr.get() << endl;
	poppo->set_psoft(ptr.get());
	poppo->Operation();

	ptr.reset(new GameSoftware);
	VIVO vivo;
	Brand *pvivo = &vivo;
	pvivo->set_psoft(ptr.get());
	pvivo->Operation();

	return 0;
}