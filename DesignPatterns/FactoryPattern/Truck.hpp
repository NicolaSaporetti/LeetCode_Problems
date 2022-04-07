#include "Transport.hpp"

class Truck : public Transport
{
    public:
    Truck();
    void get_description() override;
};