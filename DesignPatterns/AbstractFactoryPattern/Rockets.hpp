#include "ArtilleryUnit.hpp"

class Rockets : public ArtilleryUnit
{
    public:
    Rockets(double cost, double damage);
    protected:
    void getDescription() override;
};