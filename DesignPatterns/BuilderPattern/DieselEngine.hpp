#ifndef DieselEngine_HPP
#define DieselEngine_HPP
#include "Engine.hpp"

class DieselEngine : public Engine
{
    public:
    DieselEngine(double horsesPower, double autonomy);
    protected:
    double horsesPower;
};
#endif