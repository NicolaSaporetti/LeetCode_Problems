#include <MilitaryUnit.hpp>

class CavalryUnit
{
    public:
    CavalryUnit(double cost, double damage);
    protected:
    void getDescription() override;
};