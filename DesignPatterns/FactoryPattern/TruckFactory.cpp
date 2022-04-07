#include "TruckFactory.hpp"
#include "Transport.hpp"
#include "Truck.hpp"

TruckFactory::~TruckFactory() {}

Transport* TruckFactory::createTransport()
{
    return new Truck();
}