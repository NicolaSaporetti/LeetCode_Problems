#include "Knights.hpp"
#include "CavalryUnit.hpp"
#include <iostream>
using namespace std;

Knights::Knights(double cost, double damage) : CavalryUnit(cost,damage)
{}

void Knights::getDescription()
{
    cout<<"I am a Knights"<<endl;
    CavalryUnit::getDescription();
}