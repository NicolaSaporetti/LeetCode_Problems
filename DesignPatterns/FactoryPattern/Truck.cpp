#include "Truck.hpp"
#include "Transport.hpp"
#include <iostream>

template<class T>
Truck<T>::Truck(T cost, T time) : Transport<T>(cost,time)
{}

template<class T>
void Truck<T>::get_description()
{
    cout<<"Truck"<<endl;
    Transport<T>::get_description();
}