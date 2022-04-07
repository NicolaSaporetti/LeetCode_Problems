#include "Riflemen.hpp"
#include "MeleeUnit.hpp"
#include <iostream>
#include <stdlib>

Riflemen::Riflemen(double cost, double damage) : MeleeUnit(cost,damage)
{}

void Riflemen::getDescription()
{
    cout<<"I am a Riflemen"<<endl;
}