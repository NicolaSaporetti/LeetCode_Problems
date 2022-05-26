#ifndef Knights_HPP
#define Knights_HPP
#include "CavalryUnit.hpp"

class Knights : public CavalryUnit
{
    public:
    Knights(double cost, double damage);
    void getDescription();
};
#endif