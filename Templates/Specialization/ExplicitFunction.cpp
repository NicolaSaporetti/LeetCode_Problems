using namespace std;
#include <iostream>

template<typename T>
void f(T param)
{
    cout<<"Generic"<<endl;
}

template<>
void f(int param)
{
    cout<<"Int specialization"<<endl;
}

int main()
{
    f(5.0);
    f(3);
}