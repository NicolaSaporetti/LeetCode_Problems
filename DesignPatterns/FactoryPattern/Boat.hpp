#ifndef Boat_HPP
#define Boat_HPP
#include "Transport.hpp"

class Boat : public Transport
{
    public:
    Boat(double cost, double time);
    void get_description();
};
#endif