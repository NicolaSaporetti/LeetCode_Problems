using namespace std;
#include <iostream>
#include <array>
#include <cstring>

template<typename T, size_t S>
ostream& pretty_print(ostream& os, array<T,S> const& arr)
{
    os<<'[';
    for(int i=0;i<S-1;i++)
    {
        os<<arr[i]<<", ";
    }
    if(S>0) os<<arr[S-1];
    os<<']'<<endl;
    return os;
}

template<size_t S>
ostream& pretty_print(ostream& os, array<char,S> const& arr)
{
    os<<'[';
    for(int i=0;i<S;i++) os<<arr[i];
    os<<']'<<endl;
    return os;
}

int main()
{
    array<int,4> a = {3,4,5,6};
    pretty_print(cout,a);
    array<char,8> b;
    strcpy(b.data(),"Template");
    pretty_print(cout,b);
}