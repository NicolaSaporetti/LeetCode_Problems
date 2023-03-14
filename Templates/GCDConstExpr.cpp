using namespace std;
#include <cassert>

template<typename T>
constexpr T gcd(T a,T b)
{
    return (b==0)? a : gcd(b,a%b);
}

int main()
{
    assert(gcd(4,2)==2);
    assert(gcd(4,8)==4);
    assert(gcd(4,29)==1);
    assert(gcd(13,27)==1);
    assert(gcd(42,21)==21);
    assert(gcd(123,31)==1);
    assert(gcd(25600000,1)==1);
}