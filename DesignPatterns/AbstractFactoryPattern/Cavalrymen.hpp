#include "CavalryUnit.hpp"

class Cavalrymen : public CavalryUnit
{
    public:
    Cavalrymen(double cost, double damage);
    protected:
    void getDescription() override;
};