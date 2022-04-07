#include "BoatFactory.hpp"
#include "Transport.hpp"
#include "Boat.hpp"

BoatFactory::~BoatFactory() {}

Transport* BoatFactory::createTransport()
{
    return new Boat(3.5, 10.2);
}