#include <iostream>
using namespace std;

template<class T>
T sum(T a, T b)
{
    cout<<"Using standard sum"<<endl;
    return a+b;
}

template<>
double sum(double a, double b)
{
    cout<<"Using double sum"<<endl;
    return a+b;
}

template<>
string sum(string a, string b)
{
    cout<<"Using string sum"<<endl;
    return a+b;
}