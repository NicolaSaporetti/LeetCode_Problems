#include "Rockets.hpp"
#include "AviationUnit.hpp"
#include <iostream>
#include <stdlib>

AirForces::AirForces(double cost, double damage) : AviationUnit(cost,damage)
{}

void AirForces::getDescription()
{
    cout<<"I am an Air Forces"<<endl;
}