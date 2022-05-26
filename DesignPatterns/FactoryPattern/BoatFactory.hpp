#ifndef BoatFactory_HPP
#define BoatFactory_HPP
#include "Transport.hpp"
#include <memory>
#include "LogisticsFactory.hpp"

class BoatFactory : public LogisticsFactory
{
    public:
    ~BoatFactory() override;
    unique_ptr<Transport> createTransport() override;
};
#endif