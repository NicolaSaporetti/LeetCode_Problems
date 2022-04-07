#include "CavalryUnit.hpp"
#include "Cavalrymen.hpp"
#include <iostream>
#include <stdlib>

Cavalrymen::Cavalrymen(double cost, double damage) : CavalryUnit(cost,damage)
{}

void Cavalrymen::getDescription()
{
    cout<<"I am a Cavalrymen"<<endl;
}