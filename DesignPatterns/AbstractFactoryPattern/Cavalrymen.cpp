#include "Cavalrymen.hpp"
#include "CavalryUnit.hpp"
#include <iostream>
using namespace std;

Cavalrymen::Cavalrymen(double cost, double damage) : CavalryUnit(cost,damage)
{}

void Cavalrymen::getDescription()
{
    cout<<"I am a Cavalrymen"<<endl;
    CavalryUnit::getDescription();
}