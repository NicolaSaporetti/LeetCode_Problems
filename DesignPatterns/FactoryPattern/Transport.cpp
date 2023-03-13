#include "Transport.hpp"
#include <iostream>
using namespace std;

template<class T>
Transport<T>::Transport(T cost, T time): cost(cost), time(time)
{}

template<class T>
Transport<T>::~Transport()
{}

template<class T>
void Transport<T>::get_description()
{
    cout<<"Cost: "<<cost<<"\nTime: "<<time<<endl;
}