#ifndef TruckFactory_HPP
#define TruckFactory_HPP
#include "Transport.hpp"
#include <memory>
#include "LogisticsFactory.hpp"

class TruckFactory : public LogisticsFactory
{
    public:
    ~TruckFactory() override;
    unique_ptr<Transport> createTransport() override;
};
#endif