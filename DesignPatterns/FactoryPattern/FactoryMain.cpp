#include <iostream>
#include <stdlib.h>
#include <memory>
#include "Transport.cpp"
#include "Boat.cpp"
#include "Truck.cpp"
#include "LogisticsFactory.hpp"
#include "BoatFactory.cpp"
#include "TruckFactory.cpp"
using namespace std;

int main()
{
    unique_ptr<LogisticsFactory<double>> factory = make_unique<TruckFactory<double>>();
    unique_ptr<Transport<double>> transport = factory->createTransport();
    transport->get_description();
    factory = make_unique<BoatFactory<double>>();
    transport = factory->createTransport();
    transport->get_description();

    return 0;
}