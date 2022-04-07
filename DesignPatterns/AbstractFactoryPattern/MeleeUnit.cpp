#include "MeleeUnit.hpp"
#include <iostream>
#include <stdlib>

MeleeUnit::MeleeUnit(double cost, double damage) : MilitaryUnit(cost,damage)
{}

void MeleeUnit::getDescription()
{
    cout<<"Melee Unit"<<endl;
}