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

template<typename T, typename Predicate>
int count_if_template(T start, T end, Predicate p)
{
    int total = 0;
    for(T i=start;i!=end;i++)
    {
        if(p(*i)) total++;
    }
    return total;
}