#ifndef TruckFactory_HPP
#define TruckFactory_HPP
#include "Transport.hpp"
#include "LogisticsFactory.hpp"

class TruckFactory : public LogisticsFactory
{
    public:
    ~TruckFactory() override;
    Transport* createTransport() override;
};
#endif