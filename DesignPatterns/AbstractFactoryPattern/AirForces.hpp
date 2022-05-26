#ifndef AirForces_HPP
#define AirForces_HPP
#include "AviationUnit.hpp"

class AirForces : public AviationUnit
{
    public:
    AirForces(double cost, double damage);
    void getDescription();
};
#endif