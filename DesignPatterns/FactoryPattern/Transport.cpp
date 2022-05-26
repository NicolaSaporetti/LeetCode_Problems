#include "Transport.hpp"
#include <iostream>
using namespace std;

Transport::Transport(double cost, double time): cost(cost), time(time)
{}

Transport::~Transport()
{}

void Transport::get_description()
{
    cout<<"Cost: "<<cost<<"\nTime: "<<time<<endl;
}