#include "Truck.hpp"
#include "Transport.hpp"
#include <iostream>

Truck::Truck(double cost, double time) : Transport(cost,time)
{} 

void Truck::get_description()
{
    cout<<"Truck"<<endl;
    Transport::get_description();
}