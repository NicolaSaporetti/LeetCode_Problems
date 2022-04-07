#include <MilitaryUnit.hpp>

class ArtilleryUnit
{
    public:
    ArtilleryUnit(double cost, double damage);
    protected:
    void getDescription() override;
};