#ifndef Truck_HPP
#define Truck_HPP
#include "Transport.hpp"

template<class T>
class Truck : public Transport<T>
{
    public:
    Truck(T cost, T time);
    void get_description();
};
#endif