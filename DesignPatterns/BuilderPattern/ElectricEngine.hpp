#ifndef ElectricEngine_HPP
#define ElectricEngine_HPP
#include "Engine.hpp"

class ElectricEngine : public Engine
{
    public:
    ElectricEngine(double volts, double autonomy);
    protected:
    double volts;
};
#endif