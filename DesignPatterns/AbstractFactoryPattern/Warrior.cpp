#include "Warrior.hpp"
#include "MeleeUnit.hpp"
#include <iostream>
#include <stdlib>

Warrior::Warrior(double cost, double damage) : MeleeUnit(cost,damage)
{}

void Warrior::getDescription()
{
    cout<<"I am a Warrior"<<endl;
}