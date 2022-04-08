#ifndef ModernInfantry_HPP
#define ModernInfantry_HPP
#include "MeleeUnit.hpp"

class ModernInfantry : public MeleeUnit
{
    public:
    ModernInfantry(double cost, double damage);
    void getDescription();
};
#endif