#include "Truck.hpp"
#include <iostream>
#include <stdlib.h>

Truck::Truck() : cost(10.5), time(3.4)
{}

void Truck::get_description()
{
    cout<<"Boat\nCost: "<<cost<<"\nTime: "<<time<<endl;
}