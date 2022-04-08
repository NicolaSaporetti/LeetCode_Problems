#ifndef AviationUnit_HPP
#define AviationUnit_HPP
#include "MilitaryUnit.hpp"

class AviationUnit : public MilitaryUnit
{
    public:
    AviationUnit(double cost, double damage);
    virtual void getDescription();
};
#endif