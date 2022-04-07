#include "CavalryUnit.hpp"

class Tanks : public CavalryUnit
{
    public:
    Tanks(double cost, double damage);
    protected:
    void getDescription() override;
};