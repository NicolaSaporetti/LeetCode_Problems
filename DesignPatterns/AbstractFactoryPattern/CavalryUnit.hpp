#ifndef CavalryUnit_HPP
#define CavalryUnit_HPP
#include "MilitaryUnit.hpp"

class CavalryUnit : public MilitaryUnit
{
    public:
    CavalryUnit(double cost, double damage);
    virtual void getDescription();
};
#endif