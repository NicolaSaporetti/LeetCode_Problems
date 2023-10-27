#include "../../Structures/binpow.cpp"
using namespace std;

class Solution {
public:
    int countGoodNumbers(long long n) {
        int mod = 1e9+7;
        long long even = binpowWithModulo(5,(n+1)/2, mod);
        long long odd = binpowWithModulo(4,n/2,mod);
        return (even*odd)%mod;
    }
};