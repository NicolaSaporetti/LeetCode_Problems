#include "ModernInfantry.hpp"
#include "MeleeUnit.hpp"
#include <iostream>
using namespace std;

ModernInfantry::ModernInfantry(double cost, double damage) : MeleeUnit(cost,damage)
{}

void ModernInfantry::getDescription()
{
    cout<<"I am a Modern Infantry"<<endl;
    MeleeUnit::getDescription();
}