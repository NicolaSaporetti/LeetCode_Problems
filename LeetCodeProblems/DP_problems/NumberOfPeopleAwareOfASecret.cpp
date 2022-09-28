#include <vector>

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> k(n,0);
        vector<int> f(n,0);
        int mod = 1000000007;
        k[0]=1;
        for(int i=0;i<n;i++)
        {
            for(int j=delay;j<forget && i+j<n;j++)
            {
                k[i+j]=(k[i+j]+k[i])%mod;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(i+forget<n) f[i+forget]=(f[i+forget]+k[i])%mod;
        }
        for(int i=0;i<n;i++) k[i] = (k[i]+mod-f[i])%mod;
        for(int i=1;i<n;i++) k[i]=(k[i]+k[i-1])%mod;
        return k[n-1];
    }
};