#include "AviationUnit.hpp"
#include "MilitaryUnit.hpp"
#include <iostream>
using namespace std;

AviationUnit::AviationUnit(double cost, double damage) : MilitaryUnit(cost,damage)
{}

void AviationUnit::getDescription()
{
    cout<<"Aviation Unit"<<endl;
    MilitaryUnit::getDescription();
}