#include <vector>
using namespace std;

class Solution {
public:
    int knightDialer(int n) {
        vector<int> v(10,1);
        int res = 0;
        int mod = 1e9+7;
        for(int i=1;i<n;i++)
        {
            vector<int> t(10,0);
            t[0]=(v[4]+v[6])%mod;
            t[1]=(v[6]+v[8])%mod;
            t[2]=(v[7]+v[9])%mod;
            t[3]=(v[4]+v[8])%mod;
            t[4]=((v[3]+v[0])%mod+v[9])%mod;
            t[5]=0;
            t[6]=((v[1]+v[7])%mod+v[0])%mod;
            t[7]=(v[2]+v[6])%mod;
            t[8]=(v[1]+v[3])%mod;
            t[9]=(v[2]+v[4])%mod;
            v = t;
        }
        for(int i=0;i<10;i++) res = (res+v[i])%mod;
        return res;
    }
};