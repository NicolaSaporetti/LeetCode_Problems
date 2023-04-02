using namespace std;
#include <iostream>

template<typename... T>
struct tag{};

template<typename T, typename U, typename ...Args>
void tagger()
{
    tag<T,U,Args...> t1;
    tag<T,Args...,U> t2;
    tag<Args...,T,U> t3;
    tag<U,T,Args...> t4;
}

int main()
{
}