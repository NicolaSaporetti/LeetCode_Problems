#ifndef Boat_HPP
#define Boat_HPP
#include "Transport.hpp"

template<class T>
class Boat : public Transport<T>
{
    public:
    Boat(T cost, T time);
    void get_description();
};
#endif