#include "Transport.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

Transport::Transport(double cost, double time): cost(cost), time(time)
{}

Transport::~Transport()
{}

void Transport::get_description()
{
    cout<<"Boat\nCost: "<<cost<<"\nTime: "<<time<<endl;
}