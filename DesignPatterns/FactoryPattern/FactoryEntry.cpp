#include <iostream>
#include <stdlib.h>
#include <memory>
#include "Transport.cpp"
#include "Boat.cpp"
#include "Truck.cpp"
#include "LogisticsFactory.cpp"
#include "BoatFactory.cpp"
#include "TruckFactory.cpp"
using namespace std;

int main()
{
    unique_ptr<LogisticsFactory> factory = unique_ptr<LogisticsFactory>(new TruckFactory());
    unique_ptr<Transport> transport = factory->createTransport();
    transport->get_description();
    factory = unique_ptr<LogisticsFactory>(new BoatFactory());
    transport = factory->createTransport();
    transport->get_description();

    return 0;
}