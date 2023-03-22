#ifndef TruckFactory_HPP
#define TruckFactory_HPP
#include "Transport.hpp"
#include <memory>
#include "LogisticsFactory.hpp"

template <class T>
class TruckFactory : public LogisticsFactory<T>
{
    public:
    ~TruckFactory() override;
    unique_ptr<Transport<T>> createTransport() override;
};
#endif