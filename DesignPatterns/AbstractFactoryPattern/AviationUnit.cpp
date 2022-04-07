#include "AviationUnit.hpp"
#include <iostream>
#include <stdlib>

AviationUnit::AviationUnit(double cost, double damage) : MilitaryUnit(cost,damage)
{}

void AviationUnit::getDescription()
{
    cout<<"Aviation Unit"<<endl;
}