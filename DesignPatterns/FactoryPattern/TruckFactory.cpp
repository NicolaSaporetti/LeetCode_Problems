#include "TruckFactory.hpp"
#include "Transport.hpp"
#include "Truck.hpp"

TruckFactory::~TruckFactory() {}

unique_ptr<Transport> TruckFactory::createTransport()
{
    return unique_ptr<Truck>(new Truck(6.8, 3.2));
}