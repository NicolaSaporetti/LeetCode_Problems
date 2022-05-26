#include "MilitaryUnit.hpp"
#include <iostream>
using namespace std;

MilitaryUnit::MilitaryUnit(double cost, double damage) : cost(cost), damage(damage)
{}

void MilitaryUnit::getDescription()
{
    cout<<"Cost: "<<cost<<"\nDamage: "<<damage<<endl;
}
