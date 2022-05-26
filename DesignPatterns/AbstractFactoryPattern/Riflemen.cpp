#include "Riflemen.hpp"
#include "MeleeUnit.hpp"
#include <iostream>
using namespace std;

Riflemen::Riflemen(double cost, double damage) : MeleeUnit(cost,damage)
{}

void Riflemen::getDescription()
{
    cout<<"I am a Riflemen"<<endl;
    MeleeUnit::getDescription();
}