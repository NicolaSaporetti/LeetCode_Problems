#include <vector>
using namespace std;

class Fancy {
public:
    Fancy() {
        add = 0;
        mult = 1;
        mod = 1e9+7;
    }
    
    void append(int val) {
        long long v1 = (((mod+val-add)%mod)*modPow(mult,mod-2))%mod;
        v.push_back(v1);
    }
    
    void addAll(int inc) {
        add=(add+(long long)inc)%mod;
    }
    
    void multAll(int m) {
        mult = (mult*(long long)m)%mod;
        add = (add*(long long)m)%mod;
    }
    
    int getIndex(int idx) {
        if(idx>=v.size())return -1;
        else return ((v[idx] * mult)%mod+add)%mod;
    }

    long long moduloInverse(long long x, int y) {
        long long tot = 1, p = x;
        for (; y; y >>= 1) {
            if (y & 1)
                tot = (tot * p) % mod;
            p = (p * p) % mod;
        }
        return tot;
    }
    int mod;
    long long mult;
    long long add;
    vector<long long> v;
};