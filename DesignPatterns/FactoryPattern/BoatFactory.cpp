#include "BoatFactory.hpp"
#include "Transport.hpp"
#include "Boat.hpp"

template <class T>
BoatFactory<T>::~BoatFactory() {}

template <class T>
unique_ptr<Transport<T>> BoatFactory<T>::createTransport()
{
    return make_unique<Boat<T>>(3.5,10.2);
    //return unique_ptr<Boat<T>>(new Boat(3.5, 10.2));
}