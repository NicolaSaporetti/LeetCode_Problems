#include "Boat.hpp"
#include "Transport.hpp"
#include <iostream>
using namespace std;

template<class T>
Boat<T>::Boat(T cost, T time) : Transport<T>(cost,time)
{}

template<class T>
void Boat<T>::get_description()
{
    cout<<"Boat"<<endl;
    Transport<T>::get_description();
}