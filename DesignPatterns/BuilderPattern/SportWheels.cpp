#include "SportWheels.hpp"
#include "Wheels.hpp"
#include <iostream>

SportWheels::SportWheels() : Wheels(30, 50)
{
    cout<<"This is a set of sport wheels"<<endl;
}