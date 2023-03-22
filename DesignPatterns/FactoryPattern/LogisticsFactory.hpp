#ifndef LogisticsFactory_HPP
#define LogisticsFactory_HPP
#include <memory>
#include "Transport.hpp"
using namespace std;

template <class T>
class LogisticsFactory
{
    public:
    virtual ~LogisticsFactory() {};
    virtual unique_ptr<Transport<T>> createTransport() = 0;
};
#endif