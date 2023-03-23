using namespace std;
#include <iostream>

template<class T>
class A
{
public:
    T a;
    T b;
    A(T a, T b) : a(a), b(b) {}

    T get_sum();
};

template<class T>
T A<T>::get_sum()
{
    cout<<"Using standard sum"<<endl;
    return a+b;
}

template<>
double A<double>::get_sum()
{
    cout<<"Using double sum"<<endl;
    return a+b;
}

class foo
{
private:
    int value;
public:
    explicit foo(int const i) : value(i) {}
    operator int() const {return value;}
    foo operator+(foo const a) { return foo(value+(int)a);}
};