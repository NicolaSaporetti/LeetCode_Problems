#include "CavalryUnit.hpp"
#include "Tanks.hpp"
#include <iostream>
#include <stdlib>

Knights::Tanks(double cost, double damage) : CavalryUnit(cost,damage)
{}

void Tanks::getDescription()
{
    cout<<"I am a Tanks"<<endl;
}