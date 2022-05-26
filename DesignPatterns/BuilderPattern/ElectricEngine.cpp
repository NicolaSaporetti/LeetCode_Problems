#include "ElectricEngine.hpp"
#include "Engine.hpp"
#include <iostream>

ElectricEngine::ElectricEngine(double volts, double autonomy): Engine(autonomy), volts(volts)
{
    cout<<"ElectricEngine: volts "<<volts<<endl;
}