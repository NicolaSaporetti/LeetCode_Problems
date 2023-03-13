#include "TruckFactory.hpp"
#include "Transport.hpp"
#include "Truck.hpp"

template <class T>
TruckFactory<T>::~TruckFactory() {}

template <class T>
unique_ptr<Transport<T>> TruckFactory<T>::createTransport()
{
    return unique_ptr<Truck<T>>(new Truck(6.8, 3.2));
}