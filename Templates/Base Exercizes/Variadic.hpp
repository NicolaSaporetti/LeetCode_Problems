#include <iostream>
using namespace std;

template<typename T>
T minT(T a, T b)
{
    return min(a,b);
}

template<typename T, typename ... Args>
T minT(T a, Args... args)
{
    return min(a,minT(args...));
}