#include "CavalryUnit.hpp"
#include <iostream>
#include <stdlib>

CavalryUnit::CavalryUnit(double cost, double damage) : MilitaryUnit(cost,damage)
{}

void CavalryUnit::getDescription()
{
    cout<<"Cavalry Unit"<<endl;
}