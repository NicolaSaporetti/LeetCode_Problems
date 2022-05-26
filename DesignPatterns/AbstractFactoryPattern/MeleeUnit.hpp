#ifndef MeleeUnit_HPP
#define MeleeUnit_HPP
#include "MilitaryUnit.hpp"

class MeleeUnit : public MilitaryUnit
{
    public:
    MeleeUnit(double cost, double damage);
    virtual void getDescription();
};
#endif