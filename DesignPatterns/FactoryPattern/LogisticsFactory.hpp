#include "Transport.hpp"

class LogisticsFactory
{
    public:
    virtual ~LogisticsFactory();
    virtual Transport* createTransport() = 0;
    Transport* planDelivery();
};