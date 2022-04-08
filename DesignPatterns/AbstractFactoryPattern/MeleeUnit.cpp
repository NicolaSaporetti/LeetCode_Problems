#include "MeleeUnit.hpp"
#include <iostream>
using namespace std;

MeleeUnit::MeleeUnit(double cost, double damage) : MilitaryUnit(cost,damage)
{}

void MeleeUnit::getDescription()
{
    cout<<"Melee Unit"<<endl;
    MilitaryUnit::getDescription();
}