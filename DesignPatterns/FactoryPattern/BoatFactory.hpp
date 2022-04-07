#ifndef BoatFactory_HPP
#define BoatFactory_HPP
#include "Transport.hpp"
#include "LogisticsFactory.hpp"

class BoatFactory : public LogisticsFactory
{
    public:
    ~BoatFactory() override;
    Transport* createTransport() override;
};
#endif