#include "ArtilleryUnit.hpp"
#include <iostream>
#include <stdlib>

ArtilleryUnit::ArtilleryUnit(double cost, double damage) : MilitaryUnit(cost,damage)
{}

void ArtilleryUnit::getDescription()
{
    cout<<"Artillery Unit"<<endl;
}