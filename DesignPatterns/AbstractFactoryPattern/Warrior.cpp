#include "Warrior.hpp"
#include "MeleeUnit.hpp"
#include <iostream>
using namespace std;

Warrior::Warrior(double cost, double damage) : MeleeUnit(cost,damage)
{}

void Warrior::getDescription()
{
    cout<<"I am a Warrior"<<endl;
    MeleeUnit::getDescription();
}