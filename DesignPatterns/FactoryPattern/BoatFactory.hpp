#ifndef BoatFactory_HPP
#define BoatFactory_HPP
#include "Transport.hpp"
#include <memory>
#include "LogisticsFactory.hpp"

template <class T>
class BoatFactory : public LogisticsFactory<T>
{
    public:
    ~BoatFactory() override;
    unique_ptr<Transport<T>> createTransport() override;
};
#endif