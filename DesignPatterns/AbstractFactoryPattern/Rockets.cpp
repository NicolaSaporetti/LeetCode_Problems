#include "Rockets.hpp"
#include "ArtilleryUnit.hpp"
#include <iostream>
#include <stdlib>

Rockets::Rockets(double cost, double damage) : ArtilleryUnit(cost,damage)
{}

void Rockets::getDescription()
{
    cout<<"I am a Rockets"<<endl;
}