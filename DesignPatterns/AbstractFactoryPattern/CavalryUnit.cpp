#include "CavalryUnit.hpp"
#include "MilitaryUnit.hpp"
#include <iostream>
using namespace std;

CavalryUnit::CavalryUnit(double cost, double damage) : MilitaryUnit(cost,damage)
{}

void CavalryUnit::getDescription()
{
    cout<<"Cavalry Unit"<<endl;
    MilitaryUnit::getDescription();
}