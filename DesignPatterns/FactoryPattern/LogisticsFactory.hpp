#ifndef LogisticsFactory_HPP
#define LogisticsFactory_HPP
#include <memory>
#include "Transport.hpp"

class LogisticsFactory
{
    public:
    virtual ~LogisticsFactory();
    virtual unique_ptr<Transport> createTransport() = 0;
};
#endif