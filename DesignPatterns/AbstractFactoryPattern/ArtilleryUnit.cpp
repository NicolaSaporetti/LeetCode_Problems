#include "ArtilleryUnit.hpp"
#include "MilitaryUnit.hpp"
#include <iostream>
using namespace std;

ArtilleryUnit::ArtilleryUnit(double cost, double damage) : MilitaryUnit(cost,damage)
{}

void ArtilleryUnit::getDescription()
{
    cout<<"Artillery Unit"<<endl;
    MilitaryUnit::getDescription();
}