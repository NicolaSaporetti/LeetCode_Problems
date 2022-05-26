#include "Cannon.hpp"
#include "ArtilleryUnit.hpp"
#include <iostream>
using namespace std;

Cannon::Cannon(double cost, double damage) : ArtilleryUnit(cost,damage)
{}

void Cannon::getDescription()
{
    cout<<"I am a Cannon"<<endl;
    ArtilleryUnit::getDescription();
}