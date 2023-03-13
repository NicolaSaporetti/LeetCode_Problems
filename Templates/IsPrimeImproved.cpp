using namespace std;
#include <cassert>

template<class T>
constexpr bool PrimeC(T a, T b)
{
    if (b*b>a) return true;
    else return !(a%b==0) && PrimeC(a,b+1);
}

template<int a>
struct Prime
{
    constexpr static bool res = PrimeC(a,2);
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