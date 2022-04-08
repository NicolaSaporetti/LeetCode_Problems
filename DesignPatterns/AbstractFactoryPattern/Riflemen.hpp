#ifndef Riflemen_HPP
#define Riflemen_HPP
#include "MeleeUnit.hpp"

class Riflemen : public MeleeUnit
{
    public:
    Riflemen(double cost, double damage);
    void getDescription();
};
#endif