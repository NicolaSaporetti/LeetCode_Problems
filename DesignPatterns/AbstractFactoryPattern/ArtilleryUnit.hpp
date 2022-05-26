#ifndef ArtilleryUnit_HPP
#define ArtilleryUnit_HPP
#include "MilitaryUnit.hpp"

class ArtilleryUnit : public MilitaryUnit
{
    public:
    ArtilleryUnit(double cost, double damage);
    virtual void getDescription();
};
#endif