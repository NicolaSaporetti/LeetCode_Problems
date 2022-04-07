#include <iostream>
#include <stdlib.h>
#include "Transport.cpp"
#include "Boat.cpp"
#include "Truck.cpp"
#include "LogisticsFactory.cpp"
#include "BoatFactory.cpp"
#include "TruckFactory.cpp"
using namespace std;

int main()
{
    LogisticsFactory* factory = new TruckFactory();
    Transport* transport = factory->createTransport();
    transport->get_description();
    factory = new BoatFactory();
    transport = factory->createTransport();
    transport->get_description();

    return 0;
}