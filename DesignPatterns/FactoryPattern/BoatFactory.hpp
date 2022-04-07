#include "Transport.hpp"

class BoatFactory
{
    public:
    ~BoatFactory() override;
    Transport* createTransport() override;
};