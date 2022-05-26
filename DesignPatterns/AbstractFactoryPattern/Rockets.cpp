#include "Rockets.hpp"
#include "ArtilleryUnit.hpp"
#include <iostream>
using namespace std;

Rockets::Rockets(double cost, double damage) : ArtilleryUnit(cost,damage)
{}

void Rockets::getDescription()
{
    cout<<"I am a Rockets"<<endl;
    ArtilleryUnit::getDescription();
}