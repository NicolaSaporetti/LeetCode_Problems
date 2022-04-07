#include "CavalryUnit.hpp"
#include "Knights.hpp"
#include <iostream>
#include <stdlib>

Knights::Knights(double cost, double damage) : CavalryUnit(cost,damage)
{}

void Knights::getDescription()
{
    cout<<"I am a Knights"<<endl;
}