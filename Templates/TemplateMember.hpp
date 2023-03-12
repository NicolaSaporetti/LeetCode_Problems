#include <iostream>
using namespace std;

template<class T, size_t N>
T pow(T)
{
    return T*pow(T,N-1);
}