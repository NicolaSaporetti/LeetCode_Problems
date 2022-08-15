#include <iostream>
using namespace std;

template<class T>
T sum(T a, T b)
{
    return a+b;
}

int main()
{
    int a = 1;
    int b = 0;
    double c = 1.3;
    double d = 0.6;
    a= sum<int>(a,b);
    c= sum(c,d);
    cout<<a<<endl;
    cout<<c<<endl;
}