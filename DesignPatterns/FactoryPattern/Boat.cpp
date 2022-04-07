#include "Boat.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

Boat::Boat() : cost(3.5), time(8.4)
{}

void Boat::get_description()
{
    cout<<"Boat\nCost: "<<cost<<"\nTime: "<<time<<endl;
}