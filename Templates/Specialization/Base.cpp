using namespace std;
#include <iostream>

template<typename T>
struct floating_point
{
    constexpr static bool value = false;
};
template<>
struct floating_point<float>
{
    constexpr static bool value = true;
};
template<>
struct floating_point<double>
{
    constexpr static bool value = true;
};
template<>
struct floating_point<long double>
{
    constexpr static bool value = true;
};

int main()
{
    cout<<floating_point<int>::value<<endl;
    cout<<floating_point<double>::value<<endl;
    cout<<floating_point<float>::value<<endl;
    cout<<floating_point<long double>::value<<endl;
}