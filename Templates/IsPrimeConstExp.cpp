using namespace std;
#include <cassert>

constexpr bool computePrime(int a, int b)
{
    return (b*b>a)? true : !(a%b==0) && computePrime(a,b+1);
}

constexpr bool isPrime(int a)
{
    return (a<=2)? true : computePrime(a,2);
}

int main()
{
    static_assert(isPrime(1)==true);
    static_assert(isPrime(2)==true);
    static_assert(isPrime(3)==true);
    static_assert(isPrime(5)==true);
    static_assert(isPrime(6)==false);
    static_assert(isPrime(11)==true);
    static_assert(isPrime(16)==false);
    static_assert(isPrime(25)==false);
    static_assert(isPrime(29)==true);
    static_assert(isPrime(31)==true);
    static_assert(isPrime(1001)==false);
    static_assert(isPrime(99999999)==false);
}