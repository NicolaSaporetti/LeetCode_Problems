using namespace std;
#include <cassert>

template<int a, int b>
struct gcd
{
    constexpr static int res = gcd<b,a%b>::res;
};

template<int a>
struct gcd<a, 0>
{
    constexpr static int res = a;
};

int main()
{
    static_assert(gcd<4,2>::res==2);
    static_assert(gcd<4,8>::res==4);
    static_assert(gcd<4,29>::res==1);
    static_assert(gcd<13,27>::res==1);
    static_assert(gcd<42,21>::res==21);
    static_assert(gcd<123,31>::res==1);
    static_assert(gcd<256,192>::res==64);
}