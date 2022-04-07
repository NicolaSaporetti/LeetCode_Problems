#include "Riflemen.hpp"
#include "MeleeUnit.hpp"
#include <iostream>
#include <stdlib>

ModernInfantry::ModernInfantry(double cost, double damage) : MeleeUnit(cost,damage)
{}

void ModernInfantry::getDescription()
{
    cout<<"I am a Modern Infantry"<<endl;
}