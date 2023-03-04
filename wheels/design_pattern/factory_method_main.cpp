#include "car.hpp"
#include "factory_car_series.hpp"
using namespace design_pattern;

int main()
{
	FactoryBMW fbmw;
	FactoryCarBase *pfac_base = &fbmw;
	Car *bmw = pfac_base->CreateCar();
	bmw->name();

	FactoryNIO fnio;
	pfac_base = &fnio;
	Car *nio = pfac_base->CreateCar();
	nio->name();
	
	return 0;
}
