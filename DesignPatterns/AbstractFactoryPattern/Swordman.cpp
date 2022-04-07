#include "Swordmen.hpp"
#include "MeleeUnit.hpp"
#include <iostream>
#include <stdlib>

Swordmen::Swordmen(double cost, double damage) : MeleeUnit(cost,damage)
{}

void Swordmen::getDescription()
{
    cout<<"I am a Swordmen"<<endl;
}