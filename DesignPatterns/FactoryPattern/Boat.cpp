#include "Boat.hpp"
#include "Transport.hpp"
#include <iostream>
using namespace std;

Boat::Boat(double cost, double time) : Transport(cost,time)
{}

void Boat::get_description()
{
    cout<<"Boat"<<endl;
    Transport::get_description();
}