#include "car.hpp"
#include "factory_car.hpp"
using namespace design_pattern;

int main()
{
    FactoryCar fac;
    Car *pbmw = fac.CreateCar("BMW");
    Car *pnio = fac.CreateCar("NIO");
    pbmw->name();
    pnio->name();
    
    return 0;
}
