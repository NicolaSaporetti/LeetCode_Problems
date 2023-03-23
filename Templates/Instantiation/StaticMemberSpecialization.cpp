using namespace std;
#include <iostream>

template<typename T>
struct foo
{
    static T data;
};
template<typename T>
T foo<T>::data = 0;

int main()
{
    foo<int> a;
    foo<double> b;
    foo<double> c;
    cout<<a.data<<" "<<b.data<<" "<<c.data<<endl;
    a.data=1;
    b.data=2;
    c.data=3;
    cout<<a.data<<" "<<b.data<<" "<<c.data<<endl;
}