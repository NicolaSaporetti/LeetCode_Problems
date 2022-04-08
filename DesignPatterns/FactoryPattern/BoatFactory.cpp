#include "BoatFactory.hpp"
#include "Transport.hpp"
#include "Boat.hpp"

BoatFactory::~BoatFactory() {}

unique_ptr<Transport> BoatFactory::createTransport()
{
    return unique_ptr<Boat>(new Boat(3.5, 10.2));
}