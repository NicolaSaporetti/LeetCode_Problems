using namespace std;

typedef long long ll;

class Solution {
public:
    int minNonZeroProduct(int p) {
        ll mod = 1e9+7;
        ll res = ((ll(1) << p) - 1) % mod;
        ll base = ((ll(1) << p) - 2) % mod;
        ll power = (ll(1) << (p - 1)) - 1;
        while (power) {
            if (power % 2) {
                res = (res * base) % mod;
            }
            base = (base * base) % mod;
            power >>= 1;
        }
        return res;
    }
};