#include "Tanks.hpp"
#include "CavalryUnit.hpp"
#include <iostream>
using namespace std;

Tanks::Tanks(double cost, double damage) : CavalryUnit(cost,damage)
{}

void Tanks::getDescription()
{
    cout<<"I am a Tanks"<<endl;
    CavalryUnit::getDescription();
}