#include "AirForces.hpp"
#include "AviationUnit.hpp"
#include <iostream>
using namespace std;

AirForces::AirForces(double cost, double damage) : AviationUnit(cost,damage)
{}

void AirForces::getDescription()
{
    cout<<"I am an Air Forces"<<endl;
    AviationUnit::getDescription();
}