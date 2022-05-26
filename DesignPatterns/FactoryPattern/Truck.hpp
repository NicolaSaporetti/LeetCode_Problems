#ifndef Truck_HPP
#define Truck_HPP
#include "Transport.hpp"

class Truck : public Transport
{
    public:
    Truck(double cost, double time);
    void get_description();
};
#endif