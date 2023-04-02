#include <iostream>
using namespace std;

template<typename... Args>
auto sum(Args... args)
{
    return (...+args);
}

template<typename... Args>
auto sum_from_zero(Args... args)
{
    return (0+...+args);
}

template<int... args>
constexpr int sum_compile_time = (0+...+args);

int main()
{
    static_assert((sum_compile_time<1,2,8,9>)==20);
    cout<<sum(1,2,4,6)<<endl;
    cout<<sum_from_zero()<<endl;
}