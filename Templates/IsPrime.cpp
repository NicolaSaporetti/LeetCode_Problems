using namespace std;
#include <cassert>

template<int a, int b>
struct PrimeC
{
    constexpr static bool res = !(a%b==0) && PrimeC<a,b-1>::res;
};

template<int a>
struct PrimeC<a,1>
{
    constexpr static bool res = true;
};

template<int a>
struct PrimeC<a,2>
{
    constexpr static bool res = true;
};

template<int a>
struct Prime
{
    constexpr static bool res = PrimeC<a,a/2>::res;
};

template<>
struct Prime<1>
{
    constexpr static bool res = true;
};

template<>
struct Prime<2>
{
    constexpr static bool res = true;
};

int main()
{
    static_assert(Prime<1>::res==true);
    static_assert(Prime<2>::res==true);
    static_assert(Prime<3>::res==true);
    static_assert(Prime<5>::res==true);
    static_assert(Prime<6>::res==false);
    static_assert(Prime<11>::res==true);
    static_assert(Prime<16>::res==false);
    static_assert(Prime<25>::res==false);
    static_assert(Prime<29>::res==true);
    static_assert(Prime<153>::res==false);
    static_assert(Prime<1001>::res==false);
}