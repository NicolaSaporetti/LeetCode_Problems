using namespace std;
#include <iostream>

template<typename T, typename... Args>
T sum(T a, Args... args)
{
    if constexpr(sizeof ...(args) == 0) return a;
    else return a + sum(args...);
};

template<typename T>
T sum2(T a)
{
    return a;
};

template<typename T, typename... Args>
T sum2(T a, Args... args)
{
    return a + sum(args...);
};

int main()
{
    cout<<sum(1,2,3,4,5,6,7)<<endl;
    cout<<sum2(1,2,3,4,5,6,7)<<endl;
}