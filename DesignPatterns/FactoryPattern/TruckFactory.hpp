#include "Transport.hpp"

class TruckFactory
{
    public:
    ~TruckFactory() override;
    Transport* createTransport() override;
};