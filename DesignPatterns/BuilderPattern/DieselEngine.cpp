#include "DieselEngine.hpp"
#include "Engine.hpp"
#include <iostream>

DieselEngine::DieselEngine(double horsesPower, double autonomy): Engine(autonomy), horsesPower(horsesPower)
{
    cout<<"DieselEngine: horserPoser "<<horsesPower<<endl;
}