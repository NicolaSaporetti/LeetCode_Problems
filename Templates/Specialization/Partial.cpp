using namespace std;
#include <iostream>

template<typename T, int S>
struct col
{
    void operator()()
    {
        cout<<"Primary template"<<endl;
    }
};

template<int S>
struct col<int, S>
{
    void operator()()
    {
        cout<<"Integer template"<<endl;
    }
};

template<typename T>
struct col<T, 30>
{
    void operator()()
    {
        cout<<"30 template"<<endl;
    }
};

template<>
struct col<int, 30>
{
    void operator()()
    {
        cout<<"Int 30 template"<<endl;
    }
};

int main()
{
    col<char,42> a;
    a();
    col<char,30> b;
    b();
    col<int,5> c;
    c();
    col<int,30> d;
    d();
}