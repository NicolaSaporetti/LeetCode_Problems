#include "CavalryUnit.hpp"

class Knights : public CavalryUnit
{
    public:
    Knights(double cost, double damage);
    protected:
    void getDescription() override;
};