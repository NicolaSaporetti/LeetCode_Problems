#include "ArtilleryUnit.hpp"

class Cannon : public ArtilleryUnit
{
    public:
    Cannon(double cost, double damage);
    protected:
    void getDescription() override;
};